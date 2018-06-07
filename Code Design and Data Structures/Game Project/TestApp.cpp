#include "TestApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <time.h>
#include <imgui.h>
#include <exception>
#include <iostream>

TestApp::TestApp() {

}

TestApp::~TestApp() {

}

bool TestApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = nullptr;

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	try
	{
		if (m_font == nullptr) {
			throw 1;
		}
	}
	catch (int i)
	{
		std::cout << "can't load the texture" << std::endl;
	}
		//Gets the textures
	m_ship = new aie::Texture("../bin/textures/ship.png");
	m_circle = new aie::Texture("../bin/textures/ball.png");
	m_shipPos = new glm::vec2(100, 200);
	m_circlePos = new glm::vec2(100, 200);
	playerAngle = 0.0f;
	m_timer = 0.0f;
	return true;
}

void TestApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void TestApp::update(float deltaTime) {
	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		//Moves the ship right
		m_shipPos->x += 400 * deltaTime;
		//Turns the ship to face the way it is going
		playerAngle = -1.6f;

	}
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		//Moves the ship left
		m_shipPos->x -= 400 * deltaTime;
		//Turns the ship to face the way it is going
		playerAngle = 1.6f;

	}
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		//Moves the ship forward
		m_shipPos->y += 400 * deltaTime;
		//Turns the ship to face the way it is going
		playerAngle = 0;

	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		//Moves the ship down
		m_shipPos->y -= 400 * deltaTime;
		//Turns the ship to face the way it is going
		playerAngle = 3.15f;
	}


	if (input->isKeyDown(aie::INPUT_KEY_D) && input->isKeyDown(aie::INPUT_KEY_W))
	{
		m_shipPos->x += 100 * deltaTime;
		//Turns the ship to face the way it is going
		playerAngle = -0.8f;
	}
	if (input->isKeyDown(aie::INPUT_KEY_A) && input->isKeyDown(aie::INPUT_KEY_W))
	{
		m_shipPos->x += 100 * deltaTime;
		//Turns the ship to face the way it is going
		playerAngle = 0.8f;
	}
	if (input->isKeyDown(aie::INPUT_KEY_D) && input->isKeyDown(aie::INPUT_KEY_S))
	{
		m_shipPos->x += 100 * deltaTime;
		//Turns the ship to face the way it is going
		playerAngle = -2.4f;
	}
	if (input->isKeyDown(aie::INPUT_KEY_A) && input->isKeyDown(aie::INPUT_KEY_S))
	{
		m_shipPos->x += 100 * deltaTime;
		//Turns the ship to face the way it is going
		playerAngle = 2.4f;
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void TestApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	//Draws the ship
	m_2dRenderer->drawSprite(m_ship, m_shipPos->x, m_shipPos->y, 0, 0, playerAngle);



	//Makes a gui
	ImGui::Begin(" ", false ,ImGuiWindowFlags_NoTitleBar);
	//Text for the time
	ImGui::Text("Timer: %f", m_timer);
	ImGui::End();
	


	// done drawing sprites
	m_2dRenderer->end();
}