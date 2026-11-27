// File for Color palette and selection
#include "raylib.h"
#include <stdio.h>
// Going to work on this this week: Color picking. Either by a number entry (HSV) or visual palette. - Jake 

// Array that holds all of our colors. Can't really be modified since its static. If we want to add more colors we add them here
static Color Colors[MAX_COLORS_COUNT] = {
        RAYWHITE, YELLOW, ORANGE, PINK, RED, MAROON, GREEN, LIME, DARKGREEN,
        SKYBLUE, BLUE, DARKBLUE, PURPLE, VIOLET, DARKPURPLE, BEIGE, BROWN,
        LIGHTGRAY, GRAY, DARKGRAY, BLACK };

static int colorSelected = 0;


// Tels us how many colors are in our palette
int getColorCount() {
    return MAX_COLORS_COUNT;
}


// Retrieves a certain color based on our color palette 
Color getColorPalette(int index){
    if (index < 0 || index >= MAX_COLORS_COUNT) {
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
    if (index >= 0 && index < MAX_COLORS_COUNT) {
        colorSelected = index;
    }
}
