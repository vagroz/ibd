//
// Created by VaGroZ on 08.04.2019.
//

// Подключаем заголовочные файлы
#include <ExG4ActionInitialization01.hh>
#include "DetectorConstruction.h"
#include "G4RunManager.hh" // RunManager, класс из ядра Geant4,
//должен быть включен обязательно
#include "G4UImanager.hh" // Менеджер взаимодействия с пользователем
#include "ExG4DetectorConstruction01.hh" // Структура детектора,
//должен определяться пользователем
#include "FTFP_BERT.hh" // Подключается физика и частицы
// используемые в проекте, использов предопределенный в Geant4
#include "ActionInit.h" // Пользовательские классы
//для получения данных о процессе моделирования
#ifdef G4UI_USE //Если используется интерфейс пользователя
#include "G4VisExecutive.hh"//Визуализация
#include "G4UIExecutive.hh"//Выбор соответствуещего интерфейса пользователя
#endif

int main(int argc,char** argv)
{

    CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
    CLHEP::HepRandom::setTheSeed(time(NULL));

    G4RunManager* runManager = new G4RunManager;
    runManager->SetUserInitialization(new DetectorConstruction);
    runManager->SetUserInitialization(new FTFP_BERT);
    runManager->SetUserInitialization(new ActionInit);

    runManager->Initialize();

    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();
// get the pointer to the UI manager and set verbosities
// Получение указателя на менеджера взаимодействия с пользователем
// нужен, что бы можно было отправлять команды в проект
    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    if ( argc == 1 ) {//Если в командной строке есть параметр
// interactive mode : define UI session
#ifdef G4UI_USE
        G4UIExecutive* ui = new G4UIExecutive(argc, argv);//Создание интерфейса пользователя
        UImanager->ApplyCommand("/control/execute vis.mac");//Отрисовка по умолчанию
        ui->SessionStart();//Запуск интерфейса пользователя
        delete ui;//Удаление интерфейса пользователя
#endif
    }
    else {
// batch mode
// Пакетный режим
        G4String command = "/control/execute ";//Команда выполнить
        G4String fileName = argv[1];//Имя файла из командной строки при запуске проекта
        UImanager->ApplyCommand(command+fileName);//Выполнение команды
    }
// Окончание работы, вызов деструктора (удаление) G4RunManager
    delete runManager;
    return 0;
}