#include <iostream>
#include "Ticket.h"
#include "Exhibit.h"
#include "ExhibitInformation.h"
#include "InteractiveMap.h"
#include "Visitor.h"
#include "DigitalAssistant.h"
#include "Guide.h"
#include "ISpeed.h"
#include "IOrder.h"
#include "SlowSpeed.h"
#include "FastSpeed.h"
#include "OrderWeb.h"
#include "OrderMuseum.h"
#include "TicketProxy.h"
#include "Order.h"
#include "ExhibitAdapter.h"
#include "RouteDecorator.h"
#include "HighlightDecorator.h"
#include "Hall.h"
#include "Iterator.h"
#include "HallFactory.h"
#include "ExhibitSingleton.h"


int main() {
    /* ПРОКСИ И ДЕЛЕГИРОВАНИЕ
    /Ticket ticket;
    ticket.bookTicket();
    ticket.getTicket(1);
    
    // Использование прокси для билета
    TicketProxy ticketProxy;
    ticketProxy.bookTicket();
    ticketProxy.cancelTicket();
    OrderMuseum orderType;
    Order order(&orderType, 1);
    std::cout << order.getTypeOfOrder() << std::endl;
    std::cout << "\nInput Ticket number to find: ";
    int idTicket; std::cin >> idTicket;
    ticketProxy.getTicket(idTicket);
    */
    // Делегирование 
    // СОСТОЯНИЕ И НАБЛЛЮДАТЕЛЬ
    FastSpeed speed; // Создаем объект класса скорости
    Guide guide(&speed, new ReadyState()); 
    // Создаем команду экскурсии
    ExcursionCommand excursionCmd(&guide);

    // Устанавливаем содержимое экскурсии
    std::vector<std::string> content1 = { "Добро пожаловать на экскурсию!", "Сегодня мы увидим много интересного." };
    guide.setContentToSpeech(content1);

    // Выполняем команду экскурсии и сохраняем состояние
    std::cout << "Начало экскурсии 1:" << std::endl;
    excursionCmd.execute();

    // Изменяем содержимое экскурсии
    std::vector<std::string> content2 = { "Теперь мы перейдем к следующему экспонату.", "Обратите внимание на эту картину." };
    guide.setContentToSpeech(content2);

    // Выполняем команду экскурсии и сохраняем состояние
    std::cout << "Начало экскурсии 2:" << std::endl;
    excursionCmd.execute();

    // Восстанавливаем предыдущее состояние экскурсии
    std::cout << "Восстановление предыдущей экскурсии:" << std::endl;
    excursionCmd.undo();
    Visitor visitor;
    guide.attach(&visitor);
    guide.excursion(); // Начинаем эк
    guide.setState(new ExcursionState());
    guide.notify("Состояние гида изменилось!");
    //guide.excursion(); // Вызываем метод экскурсии гида

    // КОМАНДА
    // Создание команды экскурсии
    ICommand* excursionCommand = new ExcursionCommand(&guide);
    // Создание исполнителя команд
    Invoker invoker;
    // Установка команды для выполнения
    invoker.setCommand(excursionCommand);
    // Выполнение команды
    std::cout << "!-Вызываем эскурсию через команду, когда состояние гида: ведет эскурсию-!" << std::endl;
    invoker.executeCommand();
    delete excursionCommand;

    // АДАПТЕР
    ExhibitInformation exhInf1("Картина Казимира Малевича, созданная в 1915 году.");
    Exhibit exhibit1(1, "Черный квадрат", { "холст", "масляные краски" }, exhInf1);
    
    ExhibitInformation exhInf2("Картина Леонардо да Винчи, одно из самых известных произведений живописи.");
    Exhibit exhibit2(2, "Моно Лиза", { "Доска (тополь)", "масляные краски" }, exhInf2);
   
    std::cout << exhibit1.getInfo() << std::endl;
    //std::cout << "\n!Адаптер";
    ExhibitAdapter adapter(exhibit1, guide);
    adapter.getInfo();
    
    guide.stopExcursion();
    guide.excursion(); // Вызываем метод экскурсии гида

    // ДЕКОРАТОР
    std::cout << "\n!Декоратор";
    InteractiveMap baseMap;
    RouteDecorator routeDecorator(&baseMap, {"Главный зал", "Зал A", "Зал Б", "Выход"});
    HighlightDecorator highlightDecorator(&baseMap, { "Мона Лиза", "Черный квадрат"});
    std::cout << std::endl;
    routeDecorator.display();
    std::cout << std::endl;
    highlightDecorator.display();

    // КОМПОНОВЩИК
    std::cout << "\n!Компоновщик" << std::endl;
    Hall hall1("Главный зал");
    hall1.add(&exhibit1);
    hall1.add(&exhibit2);
    std::cout << hall1.getInfo();
    guide.addExhibit(&exhibit1);
    guide.addExhibit(&exhibit2);
    std::cout << "Экспонаты которые знает Гид: " << std::endl;
    for (auto ex : guide.getExhibits()) {
        std::cout << ex->getName() << std::endl;
    }

    // ИТЕРАТОР
    std::cout << "!Итератор" << std::endl;
    Iterator* iterator = hall1.createIterator();
    // Обходим все элементы в зале с помощью итератора
    std::cout << "Элементы в зале " + hall1.getName() << std::endl;
    for (iterator->first(); !iterator->isDone(); iterator->next()) {
        Component* component = iterator->currentItem();
        std::cout << component->getName() << std::endl;
    }
    delete iterator; // Освободить память

    // ФАБРИЧНЫЙ МЕТОД
    std::cout << "\n!Фабричный метод" << std::endl;
    // Создаем фабрику для картины
    PaintingFactory paintingFactory;
    // Создаем фабрику для скульптуры
    SculptureFactory sculptureFactory;
    // Создаем картины
    IExhibit* painting1 = paintingFactory.createExhibit(3, "Апофеоз войны", { "Масло", "Холст" }, "1600x1200");
    // Создаем скульптуры
    IExhibit* sculpture1 = sculptureFactory.createExhibit(1, "Родина мать", { "бетон" }, "");
    sculpture1->restavration();
    painting1->restavration();
    painting1->info();

    // СИНГЛТОН
    ExhibitSingleton* singleton = ExhibitSingleton::getInstance();
    // Создаем экспонат и логируем его создание
    for (auto ex : hall1.getCollection()) {
        singleton->logExhibitCreation(ex->getName(), hall1.getName());
    } 

    // ПРОТОТИП
    std::cout << "\n!Прототип" << std::endl;
    // Создание оригинального экспоната скульптуры
    ExhibitInformation unknw; //информации нет об экспонатах
    Painting* paint = new Painting(0, "Крик", { "" }, unknw, 1000, 1000);
    paint->displayInfo();
    std::cout << "!-Произошло клонирование-!" << std::endl;
    // Клонирование 
    Painting* clonedSculpture = paint->clone();
    clonedSculpture->displayInfo();


    // ПУЛ ЭКСПОНАТОВ
    std::cout << "\n!Пул экспонатов" << std::endl;
    std::vector<Exhibit*> pool_;
    // Закладываем экспонаты в пул
    pool_.push_back(new Painting(101, "Картина1", { "Масло", "Холст" }, unknw, 1600, 1000));
    pool_.push_back(new Painting(102, "Картина2", { "Масло", "Холст" }, unknw, 1600, 1000));
    pool_.push_back(new Sculpture(201, "Скульптура1", { "мрамор" }, unknw, 1600, 1000, 1000));
    pool_.push_back(new Sculpture(202, "Скульптура2", { "камень" }, unknw, 1600, 1000, 5000));
    ExhibitPool pool(pool_);

    std::cout << "Экспонаты пула:" << std::endl;
    // Аренда и отображение информации о картинах
    Exhibit* paint1 = pool.rentExhibit();
    if (paint1) {
        std::cout<< paint1->getName() << std::endl;
        //pool.returnExhibit(paint1);
    }
    Exhibit* paint2 = pool.rentExhibit();
    if (paint2) {
        std::cout << paint2->getName() << std::endl;
    }
    // Аренда и отображение информации о скульптурах
    Exhibit* sculpt1 = pool.rentExhibit();
    if (sculpt1) {
        std::cout << sculpt1->getName() << std::endl;

    }
    Exhibit* sculpt2 = pool.rentExhibit();
    if (sculpt2) {
        std::cout << sculpt2->getName() << std::endl;
    }
    
    // ЦЕПОЧКА
    std::cout << "\n!Цепочка обязанностей" << std::endl;
    // Создание запроса на покупку билета
    OrderWeb request("Максим", true);
    // Создание обработчиков запросов
    AuthenticationHandler authHandler;
    VIPStatusHandler vipHandler;
    // Установка цепочки обработчиков
    authHandler.setNextHandler(&vipHandler);
    // Обработка запроса
    authHandler.handleRequest(request);

    return 0;
}
