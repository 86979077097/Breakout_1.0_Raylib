#include "raylib.h"
#include "liste.h"
#include <iostream>
#include <stdlib.h>

using std::string;

class Rect
{
public:
    int x_rect, y_rect;
    int rect_width, rect_height;
    int vx, vy;
    Rect(int x_rect = 0, int y_rect = 0, int rect_width = 0, int rect_height = 0, int vx = 0, int vy = 0) : x_rect(x_rect), y_rect(y_rect), rect_width(rect_width), rect_height(rect_height), vx(vx), vy(vy) {}
};

int main()
{
    std::cout << "Programul începe...\n";
    int oko = 1;
    char *a = (char*)malloc(11 * sizeof(char));
    a[0] = 'P';
    a[1] = 'o';
    a[2] = 'i';
    a[3] = 'n';
    a[4] = 't';
    a[5] = 's';
    a[6] = ':';
    a[7] = ' ';
    a[10] = '\n';

    int width = 800, height = 600, i = 60, points = 0;
    InitWindow(width, height, "Raylib Winw");
    SetTargetFPS(60);
    std::cout << "Fereastra a fost inițializată!\n";

    Rect point(100, 100, 10, 10, 5, 5);
    Rect wood((width - 80) / 2, (height - 30), 80, 10, 5, 5);
    int ok = 1, okp = 0;
    ListNode *p1 = creere_linie();
    ListNode *p2 = creere_linie();
    ListNode *cap = nullptr;
    ListNode *capp = nullptr;

    while (!WindowShouldClose() && ok)
    {

        if (point.x_rect <= 0 || point.x_rect >= width - point.rect_width)
            point.vx = point.vx * (-1);
        if (point.y_rect <= 0 || point.y_rect >= height - point.rect_height)
            point.vy = point.vy * (-1);
        if (point.y_rect == 570 && point.x_rect >= wood.x_rect && point.x_rect <= wood.x_rect + wood.rect_width)
        {
            point.vy = point.vy * (-1);
        }
        if (point.y_rect > 572)
        {
            ok = 0;
            std::cout << "YOU LOSE" << std::endl;
        }

        point.x_rect += point.vx;
        point.y_rect += point.vy;

        if (IsKeyDown(KEY_LEFT))
            if(wood.x_rect > 0)wood.x_rect -= wood.vx;
        if (IsKeyDown(KEY_RIGHT))
            if(wood.x_rect + wood.rect_width < 800)wood.x_rect += wood.vx;

        cap = p1; // point.y_rect = 10
        if (!p1 && !p2)
            {std::cout << "WIN" << std::endl;
            ok = 0;}
        while (cap)
        {
            if (point.y_rect == 10 && point.x_rect >= cap->val1 && point.x_rect <= cap->val1 + 90)
            {
                points++;
                capp = p2;
                while (capp)
                {
                    if (capp->val1 == cap->val1)
                        oko = 0;
                    capp = capp->next2;
                }
                if (!cap->next1 || !cap->next2)
                {
                    if (!cap->next1 && !cap->next2)
                    {
                        p1 = nullptr;
                        okp = 1;
                        
                    }
                    else
                    {
                        if (!cap->next1)
                            p1 = eliminare_capete(cap);
                        else
                            eliminare_capete(cap);
                    }
                }
                else
                {
                    eliminare_intermediar(cap);
                }
                point.vy = point.vy * (-1);
                if (!oko)
                {
                    oko = 1;
                    point.vx = point.vx * (-1);
                }
            }
            if (!okp)
                cap = cap->next2;
            else
                cap = nullptr;
        }
        cap = p2;
        okp = 0;
        while (cap)
        {
            if (point.y_rect == 40 && point.x_rect >= cap->val1 && point.x_rect <= cap->val1 + 90)
            {
                points++;
                if (!cap->next1 || !cap->next2)
                {
                    if (!cap->next1 && !cap->next2)
                    {
                        p2 = nullptr;
                        okp = 1;
                        
                    }
                    else
                    {
                        if (!cap->next1)
                            p2 = eliminare_capete(cap);
                        else
                            eliminare_capete(cap);
                    }
                }
                else
                {
                    eliminare_intermediar(cap);
                }
                point.vy *= (-1);
            }
            if (!okp)
                cap = cap->next2;
            else
                cap = nullptr;
        }

        if(points >= 10){
            a[8] = points / 10 + 48;
            a[9] = points % 10 + 48;
        }
        else{a[8] = ' '; a[9] = points + 48;}

        BeginDrawing();

        ClearBackground(BLACK);
        DrawRectangle(point.x_rect, point.y_rect, point.rect_width, point.rect_height, RED);
        DrawRectangle(wood.x_rect, wood.y_rect, wood.rect_width, wood.rect_height, RED);

        ListNode *cap = nullptr;

        cap = p1;
        while (cap)
        {
            DrawRectangle(cap->val1, 10, 90, 20, RED);
            cap = cap->next2;
        }
        cap = p2;

        while (cap)
        {
            DrawRectangle(cap->val1, 40, 90, 20, ORANGE);
            cap = cap->next2;
        }
        DrawText(a, 0, 580, 20, RED);
        EndDrawing();
    }
    CloseWindow();
    std::cout << "Programul s-a terminat!\n";
    return 0;
}

/*NOTES
daca ramane un singur element in lista
daca sunt 1 rosie si una portocalie pe aceasi coloana sa inversam si vx ca poate aparea "tangeling"
*/
