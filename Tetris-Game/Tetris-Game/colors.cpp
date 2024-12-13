#include "colors.h"

const Color darkGrey = { 45, 52, 54, 255 };     // Soft Dark Grey
const Color green = { 85, 239, 196, 255 };      // Mint Green
const Color red = { 255, 118, 117, 255 };       // Light Coral Red
const Color orange = { 250, 177, 160, 255 };    // Pastel Orange
const Color yellow = { 253, 203, 110, 255 };    // Soft Yellow
const Color purple = { 162, 155, 254, 255 };    // Light Lavender
const Color cyan = { 129, 236, 236, 255 };      // Aqua Cyan
const Color blue = { 116, 185, 255, 255 };      // Sky Blue
const Color lightBlue = { 223, 230, 233, 255 }; // Light Greyish Blue
const Color darkBlue = { 9, 132, 227, 255 };    // Bold Blue

std::vector<Color> GetCellColors()
{
	return { darkGrey, green, red, orange, yellow, purple, cyan, blue, lightBlue };
}