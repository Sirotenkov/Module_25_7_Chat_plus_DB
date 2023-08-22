#include "chat.h"
#include "errno.h"

int main(int argc, char** argv)
{
    Chat* chat = nullptr;

    try
    {
        // Создаю объект класса "Чат"
        // Объект выкинет исключение если возникнут ошибки во время создания.
        chat = new Chat();
    }
    catch(...)
    {
        // На виндовс тоже есть errno так что тут всё норм.
        // errno показывает последнюю системную ошибку
        std::cout << "Failed to start chat! Error code " << errno << std::endl;
        return -1;
    }

    chat->start();

    while (chat->isChatOpen())  // Пока чат работает
    {
        chat->showLoginMenu();  // Вывожу меню входа в систему

        while (chat->getCurrentUser())  // Пока указатель на текущего пользователя не nullptr
        {
            chat->showUserMenu();  // Вывожу пользовательское меню
        }
    }
    return 0;
}
