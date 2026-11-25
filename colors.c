// File for Color palette and selection
#include "raylib.h"
#include <stdio.h>
// Going to work on this this week: Color picking. Either by a number entry (HSV) or visual palette. - Jake 

// Array that holds all of our colors. Can't really be modified
static Color Colors[MAX_COLORS_COUNT] = {
        RAYWHITE, YELLOW, GOLD, ORANGE, PINK, RED, MAROON, GREEN, LIME, DARKGREEN,
        SKYBLUE, BLUE, DARKBLUE, PURPLE, VIOLET, DARKPURPLE, BEIGE, BROWN, DARKBROWN,
        LIGHTGRAY, GRAY, DARKGRAY, BLACK };

static int colorSelected = 0;


// Tels us how many colors are in our palette
int getColorCount() {
    return colorSelected;
}


// Retrieves a certain color based on our color palette 
Color getColorPalette(int index){
    if (index < 0 || index >= colorSelected) {
        printf("Invalid color index: %d\n", index);
        return RAYWHITE; 
    }
    return Colors[index];
}

// Retrieves current selected color from the palette
Color getSelectedColor(){
    return Colors[colorSelected];
}

// Changes selected color
void setSelectedColor(int index){
    if (index < 0 || index >= colorSelected) {
        colorSelected = index;
    }
}
