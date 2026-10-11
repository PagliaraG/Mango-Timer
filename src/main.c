#include <stdio.h>
#include "raylib.h"
#include "config.h"
#include "utils.h"

typedef enum {
    MENU_SCREEN,
    TIMER_SCREEN,
    SETTINGS_SCREEN
} app_screen;

int main(void) {
    SetConfigFlags(FLAG_WINDOW_MAXIMIZED);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(1280, 720, "Mango Timer");
    SetTargetFPS(30);
    app_screen current_screen = MENU_SCREEN;
    bool exit_flag = false;

    while (!WindowShouldClose() && !exit_flag) {
        BeginDrawing();
        switch (current_screen) {
            case MENU_SCREEN: {
                ClearBackground(PRIMARY_ALT);
                float const menu_w = 500;
                float const menu_h = 200;
                Vector2 mouse_point = GetMousePosition();
                Rectangle menu_box = {
                    ((float) GetScreenWidth() - menu_w) / 2, ((float) GetScreenHeight() - menu_h) / 2, menu_w, menu_h
                };
                float const btn_w = 220;
                float const btn_h = 60;
                float btn_pad = 20;
                Rectangle start_btn = {
                    menu_box.x + btn_pad, menu_box.y + menu_box.height - btn_h - btn_pad, btn_w, btn_h
                };
                Rectangle quit_btn = {
                    menu_box.x + menu_box.width - btn_w - btn_pad, menu_box.y + menu_box.height - btn_h - btn_pad,
                    btn_w, btn_h
                };

                DrawRectangleRounded(menu_box,dynamic_roundness(menu_box,OUTER_ROUNDNESS),ROUNDNESS_SEGM,PRIMARY);
                const char *welcome_txt = "Welcome to Mango Timer";
                DrawText(welcome_txt, menu_box.x + (menu_box.width - MeasureText(welcome_txt, 32)) / 2, menu_box.y + 24, 32,
                         BLACK);

                DrawRectangleRounded(start_btn,dynamic_roundness(start_btn,INNER_ROUNDNESS),ROUNDNESS_SEGM,SECONDARY);
                const char *start_txt = "Start!";
                DrawText(start_txt, start_btn.x + (start_btn.width - MeasureText(start_txt, 32)) / 2,
                         start_btn.y + (start_btn.height - 32) / 2, 32,BLACK);

                DrawRectangleRounded(quit_btn,dynamic_roundness(quit_btn,INNER_ROUNDNESS),ROUNDNESS_SEGM,WARNING);
                const char *quit_txt = "Quit";
                DrawText(quit_txt, quit_btn.x + (quit_btn.width - MeasureText(quit_txt, 32)) / 2,
                         quit_btn.y + (quit_btn.height - 32) / 2, 32,BLACK);

                /* Buttons Logic */
                if (CheckCollisionPointRec(mouse_point,start_btn)) {
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                        current_screen = TIMER_SCREEN;
                    }
                }

                if (CheckCollisionPointRec(mouse_point,quit_btn)) {
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                        exit_flag = true;
                    }
                }
                break;
            }
            case TIMER_SCREEN:
                ClearBackground(PRIMARY_ALT);
                float const menu_w = 500;
                float const menu_h = 500;
                Vector2 mouse_point = GetMousePosition();
                Rectangle menu_box = {
                    ((float) GetScreenWidth() - menu_w) / 2, ((float) GetScreenHeight() - menu_h) / 2, menu_w, menu_h
                };

                DrawRectangleRounded(menu_box,dynamic_roundness(menu_box,OUTER_ROUNDNESS),ROUNDNESS_SEGM,PRIMARY);
                const char *title = "Start timer";
                DrawText(title, menu_box.x + (menu_box.width - MeasureText(title, 32)) / 2, menu_box.y + 24, 32,
                         BLACK);

                float const btn_w = 220;
                float const btn_h = 60;
                float btn_pad = 20;

                Rectangle start_pause_btn = {
                    menu_box.x + btn_pad, menu_box.y + menu_box.height - btn_h - btn_pad, btn_w, btn_h
                };
                Rectangle back_btn = {
                    menu_box.x + menu_box.width - btn_w - btn_pad, menu_box.y + menu_box.height - btn_h - btn_pad,
                    btn_w, btn_h
                };

                DrawRectangleRounded(start_pause_btn,dynamic_roundness(start_pause_btn,INNER_ROUNDNESS),ROUNDNESS_SEGM,SECONDARY);
                const char *start_txt = "Play/Pause";
                DrawText(start_txt, start_pause_btn.x + (start_pause_btn.width - MeasureText(start_txt, 32)) / 2,
                         start_pause_btn.y + (start_pause_btn.height - 32) / 2, 32,BLACK);

                DrawRectangleRounded(back_btn,dynamic_roundness(back_btn,INNER_ROUNDNESS),ROUNDNESS_SEGM,WARNING);
                const char *back_txt = "Menu";
                DrawText(back_txt, back_btn.x + (back_btn.width - MeasureText(back_txt, 32)) / 2,
                         back_btn.y + (back_btn.height - 32) / 2, 32,BLACK);

                if (CheckCollisionPointRec(mouse_point,back_btn)) {
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                        current_screen = MENU_SCREEN;
                    }
                }

            default: ;
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
