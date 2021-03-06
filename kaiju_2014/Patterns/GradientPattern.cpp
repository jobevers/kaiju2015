/*
 * GradientPattern.cpp
 *
 *  Created on: 21 Jan 2015
 *      Author: tully
 */

#include "GradientPattern.h"

CRGBPalette16 GradientPattern::_currentPalette;

GradientPattern::GradientPattern(const TProgmemRGBPalette16 &palette, int colorStopDensity, int gradientStepTime)
: _paletteToCopy(palette),
  _phase(0),
  _colorStopDensity(colorStopDensity),
  _gradientStepTime(gradientStepTime)
{
    reset();
}

GradientPattern::~GradientPattern() { }

void GradientPattern::reset()
{
    _currentPalette = CRGBPalette16(_paletteToCopy);
    _phase = 0;
}

void GradientPattern::update(unsigned int deltaT)
{
    _phase += deltaT;
    _phase %= _gradientStepTime * GRADIENT_INDICES;
}

void GradientPattern::draw(CRGB frameBuffer[])
{
    int offset = (_phase / _gradientStepTime);
    for (unsigned char pixelIndex = 0; pixelIndex < NUM_LEDS; ++pixelIndex) {
        unsigned char gradientIndex = ( (pixelIndex * _colorStopDensity) + offset) & 0xFF;
        frameBuffer[pixelIndex] = ColorFromPalette(_currentPalette, gradientIndex, 96, BLEND);
    }
}
