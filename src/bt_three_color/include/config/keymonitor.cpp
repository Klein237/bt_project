#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

// Place stdin en mode non canonique (pas d’attente de '\n') et désactive l’écho
void configureTerminal()
{
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Rend stdin non bloquant : getchar() renverra -1 si rien n'est tapé
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
}

// Remise à l’état initial du terminal (optionnel, si vous gérez proprement la fin)
void restoreTerminal()
{
    struct termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    oldt.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}
