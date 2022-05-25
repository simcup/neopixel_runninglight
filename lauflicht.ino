// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include <Adafruit_NeoPixel.h>

uint32_t colors[3]; //colors for easier writing of code
bool once = false;
int runningindex = 0;

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      44

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  colors[0] = pixels.Color(0,255,0);
  colors[1] = pixels.Color(0,0,255);
  colors[2] = pixels.Color(0,0,0);
}

void loop() {
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  if(! once){
    once = true;
  
  for(int i=0;i<11;i++){ // 44 leds / 4 leds per group makes 11 rounds

    for(int j=0; j<=NUMPIXELS-i*4-4; j++){ // for each pixel upto the currently not permanent ones
       if(j > 0){
        pixels.setPixelColor(j-1, colors[2]); //reset earlier pixel
       }
       for(int k = 0; k < 4; k++){ // the whole group needs love
        pixels.setPixelColor(j+k, colors[i%2]);
        pixels.show();
       }
       delay(50);
       
    }
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    //pixels.setPixelColor(i, colors[i%2]); // Moderately bright green color.
    //pixels.show(); // This sends the updated pixel color to the hardware.
    //delay(delayval); // Delay for a period of time (in milliseconds).
  }
  }else{
    int colorcounter = 0;
    bool chosencolor = 0;
    for(int i=0; i < NUMPIXELS; i++){
      if(colorcounter > 4){
        chosencolor = !chosencolor;
        colorcounter = 0;
      }
      pixels.setPixelColor(runningindex+i % NUMPIXELS, colors[chosencolor]);
      pixels.show();
      delay(50);
  }
  runningindex = runningindex+1 % NUMPIXELS;
  }
}
