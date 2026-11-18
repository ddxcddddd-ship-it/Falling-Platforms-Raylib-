#include "raylib.h"
#include <iostream>
#include <vector>
#define MAX_PLATFORMS 100
//initalize variables
int timer;

int startPlatform;

//variable of platform type
struct platforms {
	int x = GetRandomValue(0, 800);
	int y = GetRandomValue(-30, 20);
	int speed{ 1 };
	int gravity{ 1 };
};

std::vector<platforms> platform;
int amountofPlatforms;

void setup() {
	InitWindow(800, 600, "Falling Platforms");

	SetTargetFPS(60);

	// create first platform
	platform.push_back(platforms());

	// timer starts at 0
	timer = 0;
	
	// Used for drawing amount of platforms
	amountofPlatforms = 1;


}

void draw() {
	// Start drawing
	BeginDrawing();

	// Clear the screen with a color
	ClearBackground(RAYWHITE);


	// Draw the total number of platforms
	for (int i = 0; i < amountofPlatforms; i++) {
		DrawRectangle(platform[i].x, platform[i].y, 80, 20, GREEN);
	}

	// Draw the total number of platforms
	DrawText(TextFormat("Platforms: %i", amountofPlatforms), 350, 280, 20, DARKGRAY);

	// End drawing
	EndDrawing();
}
void update() {
	timer += 1;
	// create new platform every 2 seconds
	if (timer > 120) {
		platform.push_back(platforms());
		amountofPlatforms += 1;
		platform[amountofPlatforms].x = GetRandomValue(0, 800);
		platform[amountofPlatforms].y = GetRandomValue(-30, 20);
	// Reset timer
		timer = 0;
	}
	// Acceleration
	for (int i = 0; i < platform.size(); i++) {
		platform[i].y += platform[i].speed;
		platform[i].speed += platform[i].gravity;
	}
}

int main() {

	setup();
	// Main game loop
	while (!WindowShouldClose()) { 
		draw();
		update();
	}

	// Delete vector of platforms
	platform.clear();

	// Close the window and clean up resources
	CloseWindow();
	return 0;
}
