#include "snake.h"

CSnake::CSnake(CRect r, char _c /*=' '*/) : CFramedWindow(r, _c)
{
    srand(time(nullptr));
    applePosition = CPoint(rand() % geom.size.x + geom.topleft.x,
                           rand() % geom.size.y + geom.topleft.y);
    snakeHead = CPoint(2, 2);
    currentDirection = CPoint(0, 1);
    pausedDirection = CPoint(0, 0);

    snakeLength = 2;
    seconds = 0;
    moveDelay = 20;
    points = 0;
    level = 1;

    snakeBody.assign(snakeLength, snakeHead);

    fail = false;
    pause = false;
    help = false;
}

bool CSnake::handleEvent(int key)
{
    switch (key) {
    case KEY_UP:
        if (currentDirection == CPoint(0, 1) || pause)
            return true;
        currentDirection = CPoint(0, -1);
        return true;
    case KEY_DOWN:
        if (currentDirection == CPoint(0, -1) || pause)
            return true;
        currentDirection = CPoint(0, 1);
        return true;
    case KEY_RIGHT:
        if (currentDirection == CPoint(-1, 0) || pause)
            return true;
        currentDirection = CPoint(1, 0);
        return true;
    case KEY_LEFT:
        if (currentDirection == CPoint(1, 0) || pause)
            return true;
        currentDirection = CPoint(-1, 0);
        return true;
    case 'p':
        pauses();
        return true;
    case 'r':
        restart();
        return true;
    case 'h':
        help = !help;
        return true;
    case 'w':
        move(CPoint(0, -1));
        return true;
    case 'a':
        move(CPoint(0, 1));
        return true;
    case 's':
        move(CPoint(1, 0));
        return true;
    case 'd':
        move(CPoint(-1, 0));
        return true;
    };

    if (moveDelay  <= seconds) {
        seconds = 0;
        return true;
    }
    else {
        seconds++;
        return false;
    }
}

void CSnake::move_snake(CPoint direction)
{
    if (!(direction.x == 0 && direction.y == 0)) {

        snakeBody.push_front(snakeHead);
        snakeHead += direction;

        if (snakeHead.x <= geom.topleft.x) {
            snakeHead.x += geom.size.x;
        }
        if (snakeHead.x == geom.topleft.x + geom.size.x) {
            snakeHead.x = geom.topleft.x;
        }
        if (snakeHead.y <= geom.topleft.y) {
            snakeHead.y += geom.size.y;
        }
        if (snakeHead.y == geom.topleft.y + geom.size.y) {
            snakeHead.y = geom.topleft.y;
        }
        while (snakeLength < (int)snakeBody.size()) {
            snakeBody.pop_back();
        }
    }
}

void CSnake::paint()
{
    for (int y = geom.topleft.y; y < geom.topleft.y + geom.size.y; y++) {
        for (int x = geom.topleft.x; x < geom.topleft.x + geom.size.x; x++) {
            gotoyx(y, x);
            printl("%c", c);
        }
    }

    gotoyx(geom.topleft.y - 1, geom.topleft.x);
    const char* gamePaused;
    if (pause) {
        gamePaused = "Pause";
    }
    else {
        gamePaused = "";
    }

    printl("Level: %i Apples: %i %s", level, points, gamePaused);
    for (auto i = snakeBody.begin(); i != snakeBody.end(); i++) {
        if (snakeHead.x == i->x && snakeHead.y == i->y && isWithinBounds()) {
            currentDirection = 0;
            fail = true;
        }
    }

    if (fail) {
        gotoyx(geom.topleft.y + 6, geom.topleft.x + 1);
        printl("%s", "You died. Press r to start a new game");
    }
    else if (currentDirection == 0 && !pause) {
        gotoyx(geom.topleft.y + 6, geom.topleft.x + 1);
        printl("%s", "p: Pause");
        gotoyx(geom.topleft.y + 8, geom.topleft.x + 1);
        printl("%s", "h: Help");
        gotoyx(geom.topleft.y + 10, geom.topleft.x + 1);
        printl("%s", "r: Restart");
        gotoyx(geom.topleft.y + 12, geom.topleft.x + 1);
        printl("%s", "Use arrows to move");
    }
    else {
        move_snake(currentDirection);
        if (!help) {
        }
        else {
            gotoyx(geom.topleft.y + 14, geom.topleft.x + 1);
            printl("Snake Head: %i %i", snakeHead.x, snakeHead.y);
            gotoyx(geom.topleft.y + 13, geom.topleft.x + 1);
            printl("Window TopLeft: %i %i", geom.topleft.x, geom.topleft.y);
            gotoyx(geom.topleft.y + 6, geom.topleft.x + 1);
            printl("%s", "p: Pause");
            gotoyx(geom.topleft.y + 8, geom.topleft.x + 1);
            printl("%s", "h: Help");
            gotoyx(geom.topleft.y + 10, geom.topleft.x + 1);
            printl("%s", "r: Restart");
            gotoyx(geom.topleft.y + 12, geom.topleft.x + 1);
            printl("%s", "Use arrows to move");
        }
    }

    for (auto i = snakeBody.begin(); i != snakeBody.end(); i++) {
        gotoyx(i->y, i->x);
        printl("%c", '#');
    }

    gotoyx(snakeHead.y, snakeHead.x);
    printl("%c", '*');
    if (snakeHead == applePosition) {
        applePosition = CPoint(rand() % geom.size.x + geom.topleft.x,
                               rand() % geom.size.y + geom.topleft.y);
        snakeLength++;
        points++;
    }
    apples();
    if (points % 5 == 0 && level < points / 5 + 1) {
        level++;
        moveDelay -= 4;
    }
}

void CSnake::apples()
{
    gotoyx(applePosition.y, applePosition.x);
    printl("%c", 'O');
}

bool CSnake::isWithinBounds()
{
    bool is_in_x = (snakeHead.x >= geom.topleft.x) &&
                   (snakeHead.x <= geom.topleft.x + geom.size.x);
    bool is_in_y = (snakeHead.y >= geom.topleft.y) &&
                   (snakeHead.y <= geom.topleft.y + geom.size.y);
    return (is_in_x && is_in_y);
}

void CSnake::pauses()
{
    pause = !pause;
    if (pausedDirection.x == 0 && pausedDirection.y == 0) {
        pausedDirection = currentDirection;
        currentDirection.x = 0, currentDirection.y = 0;
    }
    else {
        currentDirection = pausedDirection;
        pausedDirection.x = 0, pausedDirection.y = 0;
    }
}

void CSnake::restart()
{
    applePosition = CPoint(rand() % geom.size.x + geom.topleft.x,
                           rand() % geom.size.y + geom.topleft.y);
    snakeHead = CPoint(2, 2);

    snakeLength = 2;
    seconds = 0;
    moveDelay = 20;
    points = 0;
    level = 1;

    snakeBody.clear();
    snakeBody.assign(snakeLength, snakeHead);
    currentDirection.x = 0, currentDirection.y = 0;

    fail = false;
    pause = false;
    help = false;
}
