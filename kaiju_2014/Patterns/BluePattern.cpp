/*
 * BluePattern.cpp
 *
 *  Created on: 7 Jan 2015
 *      Author: tully
 */

#include "../Patterns/BluePattern.h"

BluePattern::BluePattern() {
	// TODO Auto-generated constructor stub

}

BluePattern::~BluePattern() {
	// TODO Auto-generated destructor stub
}

void BluePattern::draw(CRGB *frameBuffer) {
	fill_solid(frameBuffer, NUM_LEDS, CRGB(0, 0, 16));
}

