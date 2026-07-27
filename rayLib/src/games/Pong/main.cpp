#include <iostream>
#include "raylib.h"

struct Player {
    Vector2 position;
    float speed;
};

struct Cpu {
    Vector2 position;
    float speed;
};

struct Ball {
    Vector2 position;
    Vector2 velocity;
    float radius;
};

int main() {

    const int WIDTH{800};
    const int HEIGHT{450};
    int score{}, cpuScore{};

    InitWindow(WIDTH, HEIGHT, "Pong");

    SetTargetFPS(165);

    Player player {
        {100, HEIGHT / 2 - 50},
        {500.0f}
    };

    Cpu cpu {
        {WIDTH - 100, HEIGHT / 2 - 50},
        {500.0f}
    };

    Ball ball {
        {WIDTH / 2, HEIGHT / 2  - 15.0f},
        {400.0f, 400.0f},
        {15.0f}
    };

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) player.position.y -= player.speed * dt;
        if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) player.position.y += player.speed * dt;

        ball.position.x += ball.velocity.x * dt;
        ball.position.y += ball.velocity.y * dt; //Makes ball move

        if (ball.position.y - ball.radius <= 0 || ball.position.y + ball.radius >= HEIGHT) {
            ball.velocity.y *= - 1.0f;
        }
        if (ball.position.x - ball.radius <= 0 || ball.position.x + ball.radius >= WIDTH) {
            ball.velocity.x *= - 1.0f; //Ball error bounds
        } 

        if (cpu.position.y + 50.0f < ball.position.y) cpu.position.y += cpu.speed * dt;
        if (cpu.position.y + 50 > ball.position.y) cpu.position.y -= cpu.speed * dt; //Makes it so cpu works


        if (player.position.y < 0) player.position.y = 0;
        if (player.position.y > HEIGHT - 100) player.position.y = HEIGHT - 100; //Player paddle error bounds

        if (cpu.position.y < 0) cpu.position.y = 0;
        if (cpu.position.y > HEIGHT - 100) cpu.position.y = HEIGHT - 100; //Cpu paddle error bounds

        Rectangle playerRect = {player.position.x, player.position.y, 30,100};
        Rectangle cpuRect = {cpu.position.x, cpu.position.y, 30,100};

        if (CheckCollisionCircleRec(ball.position, ball.radius, playerRect)) {
            if (ball.velocity.x < 0) {
                ball.velocity.x *= -1.0f;
                score ++;
               
            }
        }
        if (CheckCollisionCircleRec(ball.position, ball.radius, cpuRect)) {
            if (ball.velocity.x > 0) {
                ball.velocity.x *= - 1.0f;
                cpuScore ++;
            }
        } //Check if ball hits paddle

        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawRectangle(player.position.x, player.position.y, 30, 100, BLACK); //Draw player paddle
            DrawRectangle(cpu.position.x, cpu.position.y, 30, 100, BLACK); //Draw cpu paddle
            DrawText(TextFormat("%i", score), 20, 20, 60 , BLACK); //Draw player score
            DrawText(TextFormat("%i", cpuScore), WIDTH - 40, 20, 60 , BLACK); //Draw cpu score
            DrawCircleV(ball.position, ball.radius, BLACK); //Draw ball

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
