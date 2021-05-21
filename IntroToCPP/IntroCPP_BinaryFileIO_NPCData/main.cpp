/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "DataFile.h"

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800; // screen width
    int screenHeight = 450; // screen height

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window"); // makes window with screen width and height and a name

    DataFile data; // puts the DataFile class into a variable
    int currentRecordIdx = 0; // the current record the program looking at
    
    data.Load("npc_data.dat"); // name of the file

    DataFile::Record* currentRecord = data.GetRecord(currentRecordIdx); // creates a Record using the GetRecord function
    Texture2D recordTexture = LoadTextureFromImage(currentRecord->image); // gets the texture for the current record 


    SetTargetFPS(60);// limits fps to 60
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        if (IsKeyPressed(KEY_LEFT)) // goes to previous record
        {
            currentRecordIdx--;
            if (currentRecordIdx < 0) // checks if the currentRecordIdx does out of bounds of the list
            {
                currentRecordIdx = 0; // stops the currentRecordIdx from going out of bounds of the list
            }
            currentRecord = data.GetRecord(currentRecordIdx); // gets previous record
            recordTexture = LoadTextureFromImage(currentRecord->image); // gets image for previous record
        }

        if (IsKeyPressed(KEY_RIGHT)) // goes to next record
        {
            currentRecordIdx++;
            if (currentRecordIdx >= data.GetRecordCount())              // checks if the currentRecordIdx goes out of bounds of the list
            {
                currentRecordIdx = data.GetRecordCount() - 1;            // stops the program from exceeding the amount of records
            }
            currentRecord = data.GetRecord(currentRecordIdx);            // gets next record
            recordTexture = LoadTextureFromImage(currentRecord->image); // gets image for next record
        }


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE); // draws white background

        DrawTexture(recordTexture, 300, 50, WHITE); // draws the record texture

        DrawText("NAME", 10, 50, 20, LIGHTGRAY); // draws NAME
        DrawText(currentRecord->name.c_str(), 10, 80, 20, LIGHTGRAY); // draws the name

        DrawText("AGE", 10, 120, 20, LIGHTGRAY); // draws AGE
        DrawText(std::to_string(currentRecord->age).c_str(), 10, 150, 20, LIGHTGRAY); // draws the age

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}