#include "raylib.h"
#include <iostream>
#define MAX_PLATFORMS 100


//initalize variables
int timer;

int amountofplatforms;

//variable of platform type
struct platform {
	int x{ 400 };
	int y{ 300 };
	int speed{ 1 };
	int gravity{ 1 };
}platforms[MAX_PLATFORMS];



void setup() {
	InitWindow(800, 600, "Falling Platforms");

	SetTargetFPS(60);

	// beginning amount of platforms
	amountofplatforms = 1;
	// timer starts at 0
	timer = 0;
	// set position of first platform
	for (int i = 0; i < amountofplatforms; i++) {
		platforms[i].x = MAX_PLATFORMS;
		platforms[i].y = MAX_PLATFORMS;
	}

}

void draw() {
	// Start drawing
	BeginDrawing();

	// Clear the screen with a color
	ClearBackground(RAYWHITE);

	// Draw amount of platforms on screen
	DrawText(TextFormat("Platforms: %i", amountofplatforms), 350, 280, 20, DARKGRAY);
	
	// Draw the platforms using a for loop
	for (int i = 0; i < amountofplatforms; i++) {
		DrawRectangle(platforms[i].x, platforms[i].y, 80, 50, GRAY);
	}

	// End drawing
	EndDrawing();
}
void update() {
	
	// Timer increase per frame (60 FPS)
	timer += 1;
	// it's true every 2 seconds
	if (timer > 120) {
		amountofplatforms += 1;
		timer = 0;
	// If the amount of platforms before two seconds was 1 (platforms[0]), 
	// the new platform's position whould be 2 (platforms[1])
		platforms[amountofplatforms].x = GetRandomValue(0, 800);
		platforms[amountofplatforms].y = GetRandomValue(0, 20);
	}
	// Acceleration
	for (int i = 0; i < amountofplatforms; i++) {
		platforms[i].y += platforms[i].speed;
		platforms[i].speed += platforms[i].gravity;
	}
}

int main() {

	setup();

	while (!WindowShouldClose()) { // Main game loop
		draw();
		update();
	}

	// Close the window and clean up resources
	CloseWindow();
	return 0;
}
