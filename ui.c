// File for Toolbar, buttons, and mouse interactions 

struct rectButton {
	int topLeftXY;
	int bottomRightXY;
};

/*
 * creates a button and adds it to an array
 *
 * @param buttonArray[] is the array where all the buttons are stored
 * @param topLeftXY & bottomRightXY are the corners of the rectangle
 * @returns -1 if button wasn't able to be created
*/
int createButton(struct rectButton buttonArray[], int topLeftXY, int bottomRightXY) {
	int isSuccesful = -1;

	// check bounds of window and see if button coords are valid
	// though it might be better to check somewhere else, such as when actually drawing
	// the button because we need the screens height and width which would require extra parameters
	// allocate memory for the button and add the pointer to the inputed array

	return isSuccesful;
}

// not sure how this will be done yet
int removeButton();

/*
 * buttons shouldn't be drawn in the texture layer
 *
 * @param buttonArray is an array containing all buttons that should be drawn
 * @param numOfButtons is used to prevent traversing passed the array in memory
*/
int drawButtons(struct rectButton buttonArray[], int numOfButtons) {
	int isSuccesful = -1;



	return isSuccesful;
}
