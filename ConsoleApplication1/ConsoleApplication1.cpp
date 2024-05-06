#include <iostream>
#include <list>
#include <vector>
#include <array>
using namespace std;
class People
{
public:
    int hp = 100;
    int need_for_food = 2;
    int magic_power = 2;
    int saity = 1;
    int birthrate = 5;

    void birthrate_up() {
        birthrate += 1;
    }
};

class Elf
{
public:
    int hp = 50;
    int need_for_food = 1;
    int magic_power = 1;
    int saity = 1;
    int birthrate = 3;

    void birthrate_up() {
        birthrate += 1;
    }
};

class Ork
{
public:
    int hp = 200;
    int need_for_food = 4;
    int magic_power = 0;
    int saity = 1;
    int birthrate = 2;

    void birthrate_up() {
        birthrate += 1;
    }
};

static class fantasy_castles
{
private:
    static int food_score;
    static int magic_score;
    static vector<People> Peoples;
    static vector<Elf> Elfs;
    static vector<Ork> Orks;
    int days = 1;
    bool daycheck = true;
public:

    void birthrate_up() {
        for (Ork i : Orks) {
            i.birthrate_up();
        }
        for (People i : Peoples) {
            i.birthrate_up();
        }
        for (Elf i : Elfs) {
            i.birthrate_up();
        }
    }

    int get_people() {
        return Peoples.size();
    }

    int get_orks() {
        return Orks.size();
    }

    int get_elfs() {
        return Elfs.size();
    }

    int get_food() {
        return food_score;
    }

    int get_magic() {
        return magic_score;
    }

    int get_days() {
        return days;
    }

    void next_day()
    {
        /*if (Peoples.size() == 1)
        {
            if (Peoples[0].saity == 0)
            {
                Peoples[0].hp -= 50;
            }
            Peoples[0].saity = 0;
            if (Peoples[0].hp <= 0) {
                Peoples.clear();
            }
        }
        if (Orks.size() == 1)
        {
            
            if (Orks[0].saity == 0)
            {
                Orks[0].hp -= 100;
            }
            Orks[0].saity = 0;
            if (Orks[0].hp <= 0) {
                Orks.clear();
            }
        }
        if (Elfs.size() == 1)
        {
            
            if (Elfs[0].saity == 0)
            {
                Elfs[0].hp -= 25;
            }
            Elfs[0].saity = 0;
            if (Elfs[0].hp <= 0) {
                Orks.clear();
            }
        }*/
        daycheck = true;
        for (int i = 0; i < Peoples.size()-1; i++)
        {
            if (Peoples[i].saity == 0)
            {
                Peoples[i].hp -= 50;
            }
            if (Peoples[i].hp <= 0) {
                Peoples.erase(Peoples.begin() + i);
            }
            try
            {
                Peoples[i].saity = 0;
            }
            catch (const std::exception&)
            {
                cout << "test" << endl;
            }
        };


        for (int i = 0; i < Orks.size()-1; i++)
        {
            if (Orks[i].saity == 0)
            {
                Orks[i].hp -= 100;
            }
            if (Orks[i].hp <= 0) {
                Orks.erase(Orks.begin() + i);
            }
            try
            {
                Orks[i].saity = 0;
            }
            catch (const std::exception&)
            {
                cout << "test" << endl;
            }
        };

        for (int i = 0; i < Elfs.size()-1; i++)
        {
            if (Elfs[i].saity == 0)
            {
                Elfs[i].hp -= 25;
            }
            if (Elfs[i].hp <= 0) {
                Elfs.erase(Elfs.begin() + i);
            }
            try
            {
                Elfs[i].saity = 0;
            }
            catch (const std::exception&)
            {
                cout << "test" << endl;
            }
        };

        days++;
    };

    void feed_peoples()
    {
        for (int i = 0; i < Peoples.size(); i++)
        {
            if (food_score >= Peoples[i].need_for_food)
            {
                food_score -= Peoples[i].need_for_food;
                Peoples[i].saity = 1;
            }
            else
            {
                if (magic_score >= Peoples[i].magic_power)
                {
                    magic_score -= Peoples[i].magic_power;
                    Peoples[i].magic_power;
                }
            }
        };
    }

    void feed_orks()
    {
        for (int i = 0; i < Orks.size(); i++)
        {
            if (food_score >= Orks[i].need_for_food)
            {
                food_score -= Orks[i].need_for_food;
                Orks[i].saity = 1;
            }
        };
    }

    void feed_elfs()
    {
        for (int i = 0; i < Elfs.size(); i++)
        {
            if (food_score >= Elfs[i].need_for_food)
            {
                food_score -= Elfs[i].need_for_food;
                Elfs[i].saity = 1;
            }
            else
            {
                if (magic_score >= Elfs[i].magic_power)
                {
                    magic_score -= Elfs[i].magic_power;
                    Elfs[i].magic_power;
                }
            }
        };
    }

    void born()
    {
        if (daycheck) {
            int elfsize = Elfs.size();
            for (int i = 0; i < elfsize; i++)
            {
                if (Elfs[i].saity == 1)
                {
                    for (int j = 0; j < Elfs[i].birthrate; j++)
                    {
                        Elf elf;
                        Elfs.push_back(elf);
                    }
                }
            }

            int orksize = Orks.size();
            for (int i = 0; i < orksize; i++)
            {
                if (Orks[i].saity == 1)
                {
                    for (int j = 0; j < Orks[i].birthrate; j++)
                    {
                        Ork ork;
                        Orks.push_back(ork);
                    }
                }
            }

            int peoplesize = Peoples.size();
            for (int i = 0; i < peoplesize; i++)
            {
                if (Peoples[i].saity == 1)
                {
                    for (int j = 0; j < Peoples[i].birthrate; j++)
                    {
                        People people;
                        Peoples.push_back(people);
                    }
                }
            }
            daycheck = false;
        }
        else {
            cout << "рожать можно только один раз в день" << endl;
        }
    }

    void add_food_and_magic(int a, int b)
    {
        if (a >= 1 && b >= 1)
        {
            food_score += a;
            magic_score += b;
        }
        else
        {
            std::cout << "Данные введены неверно!" << endl;
        }
    }

    public: void start_game()
    {
        cout << "Вы начали игру" << endl;
        cout << "Введите количество еды:" << endl;
        while (!(cin >> food_score) || food_score <= 0) {
            cout << "Некорректный ввод. Введите положительное число." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Введите количество магической энергии:" << endl;
        while (!(cin >> magic_score) || magic_score <= 0) {
            cout << "Некорректный ввод. Введите положительное число." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        Elf elf;
        Ork ork;
        People human;
        Elfs.push_back(elf);
        Orks.push_back(ork);
        Peoples.push_back(human);
        Elfs.push_back(elf);
        Orks.push_back(ork);
        Peoples.push_back(human);
    }
};
int fantasy_castles::food_score;
int fantasy_castles::magic_score;
vector<People> fantasy_castles::Peoples;
vector<Elf> fantasy_castles::Elfs;
vector<Ork> fantasy_castles::Orks;

int main()
{
    setlocale(LC_ALL, "Rus");
    fantasy_castles castle;
    castle.start_game();
    int choice;
    while (true)
    {
        cout << "День " << castle.get_days() << endl;
        cout << "Количество людей " << castle.get_people() << endl;
        cout << "Количество орков " << castle.get_orks() << endl;
        cout << "Количество эльфов " << castle.get_elfs() << endl;
        cout << "Количество еды " << castle.get_food() << endl;
        cout << "Количество магии " << castle.get_magic() << endl;
        cout << "Выберите действие" << endl;
        cout << "1. Покормить людей" << endl;
        cout << "2. Покормить орков" << endl;
        cout << "3. Покормить эльфов" << endl;
        cout << "4. Начать новый день" << endl;
        cout << "5. Рожать" << endl;
        cout << "6. Добавить еду и магию" << endl;
        cout << "7. Поднять рождаемость" << endl;
        cout << "8. Выход из программы" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                castle.feed_peoples();
                cout << "Вы покормили людей" << endl;
                cout << "Количество вашей еды " << castle.get_food() << endl;
                cout << "Количество вашей магии " << castle.get_magic() << endl;
                break;
            case 2:
                castle.feed_orks();
                cout << "Вы покормили орков" << endl;
                cout << "Количество вашей еды " << castle.get_food() << endl;
                cout << "Количество вашей магии " << castle.get_magic() << endl;
                break;
            case 3:
                castle.feed_elfs();
                cout << "Вы покормили эльфов" << endl;
                cout << "Количество вашей еды " << castle.get_food() << endl;
                cout << "Количество вашей магии " << castle.get_magic() << endl;
                break;
            case 4:
                castle.next_day();
                break;
            case 5:
                castle.born();
                break;
            case 6:
                int food;
                int magic;
                cout << "Введите количество желаемой еды " << endl;
                cin >> food;
                cout << "Введите количество желаемой магии " << endl;
                cin >> magic;
                castle.add_food_and_magic(food, magic);
                break;
            case 7:
                castle.birthrate_up();
                cout << "Ура!!! Демография замка спасена" << endl;
                break;
            case 8:
                exit(0);
                break;
            default:
                cout << "Введите корректный номер действия" << endl;
                break;
        }
    }
}