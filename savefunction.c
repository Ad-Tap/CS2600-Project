//disclaimer: no load function because the argument for the function is predetermined
#include "raylib.h"

//this is basically the basic logic for saving, expansions or add ons can be added later
//implement the gui in the main and connect the button to here i think
void SaveFunction(){

        if (CheckCollisionPointRec(mousePos, btnSaveRec)) btnSaveMouseHover = true;
        else btnSaveMouseHover = false;



	if ((btnSaveMouseHover && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) || IsKeyPressed(KEY_S))
        {
            Image image = LoadImageFromTexture(target.texture);
            ImageFlipVertical(&image);
            ExportImage(image, "saved_image.png");
            UnloadImage(image);
            showSaveMessage = true; //if we wanna use this for verification
        }
}
