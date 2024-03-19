#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>
MatrixPanel_I2S_DMA *matrix = nullptr;
/*--------------------- MATRIX GPIO CONFIG  -------------------------*/
#define R1_PIN 25
#define G1_PIN 26
#define B1_PIN 27
#define R2_PIN 14
#define G2_PIN 12
#define B2_PIN 13
#define A_PIN 23
#define B_PIN 19 // Changed from library default
#define C_PIN 5
#define D_PIN 17
#define E_PIN 18
#define LAT_PIN 4
#define OE_PIN 15
#define CLK_PIN 16

int setting_pixel_width = 16;


/*--------------------- MATRIX PANEL CONFIG -------------------------*/

//Another way of creating config structure
//Custom pin mapping for all pins
HUB75_I2S_CFG::i2s_pins _pins={R1_PIN, G1_PIN, B1_PIN, R2_PIN, G2_PIN, B2_PIN, A_PIN, B_PIN, C_PIN, D_PIN, E_PIN, LAT_PIN, OE_PIN, CLK_PIN};
HUB75_I2S_CFG mxconfig(
						32,   // width
						64,   // height
						 1,   // chain length
					 _pins,   // pin mapping

  HUB75_I2S_CFG::ICN2038S
  ); // driver chip

//HUB75_I2S_CFG::clkphase = false;

MatrixPanel_I2S_DMA *dma_display = nullptr;
/*
// Module configuration
HUB75_I2S_CFG mxconfig(
	PANEL_RES_X,   // module width
	PANEL_RES_Y,   // module height
	PANEL_CHAIN    // Chain length
);
*/

//mxconfig.gpio.e = -1; // Assign a pin if you have a 64x64 panel
//mxconfig.clkphase = false; // Change this if you have issues with ghosting.
//mxconfig.driver = HUB75_I2S_CFG::ICN2038S; // Change this according to your pane.



#include <FastLED.h>



/* -------------------------- Some variables -------------------------- */
unsigned long fps = 0, fps_timer; // fps (this is NOT a matrix refresh rate!)
unsigned int default_fps = 30, pattern_fps = 30;  // default fps limit (this is not a matrix refresh counter!)
unsigned long ms_animation_max_duration = 20000;  // 20 seconds
unsigned long last_frame=0, ms_previous=0;

void setup()
{
 /************** SERIAL **************/
  Serial.begin(115200);
  delay(250);
  mxconfig.clkphase = false; // Change this if you have issues with ghosting.
  mxconfig.driver = HUB75_I2S_CFG::ICN2038S;
 /************** DISPLAY **************/
  Serial.println("...Starting Display");
  dma_display = new MatrixPanel_I2S_DMA(mxconfig);
  dma_display->begin();
  dma_display->setBrightness8(90); //0-255

  
  
  //dma_display->clearScreen();  
 // delay(1000);  
 
}


void updatePixelMatrix(int x, int y, int r, int g, int b){
  
  //invert the x axis
  x = 31 - x;  //this needs to be 1 less than the width of the matrix

  //update the LED based on x y grid position
  dma_display->drawPixelRGB888(x, y, r, g, b);
  
}


void updatePixel(int pixel_number, int r, int g = false, int b = false){
  
  //calculate the LED based on pixel number
  int y = floor(pixel_number / setting_pixel_width);
  int x = pixel_number - (y * setting_pixel_width);

  //update that led 
  updatePixelMatrix(x, y, r, g, b); 
   
}



void loop()
{
    
   /*  for(int i = 16; i<32; i++){
    for(int j = 0; j<30; j++)
    {
   dma_display->drawPixelRGB888(i, j,  25, 25, 115); //x, y cordinate
      
       Serial.print("x value :");
       Serial.print(i);
       Serial.print(" ||y value :");
       Serial.println(j);
       //delayMicroseconds(100);
       delay(500);
    }
     }
     dma_display->clearScreen();  */

     //dma_display->drawPixelRGB888(16, 1,  255, 0, 0); //x, y cordinate

     //dma_display->drawPixelRGB888(16, 2,  0, 255, 0); //x, y cordinate

/*
     dma_display->clearScreen();

     delay(1000);

     dma_display->drawPixelRGB888(30, 5,  255, 0, 0); //x, y cordinate

     dma_display->drawPixelRGB888(30, 6,  0, 255, 0); //x, y cordinate

     dma_display->drawPixelRGB888(30, 7,  0, 0, 255); //x, y cordinate

     dma_display->drawPixelRGB888(30, 8,  255, 0, 225); //x, y cordinate

     dma_display->drawPixelRGB888(30, 9,  0, 255, 225); //x, y cordinate

     delay(1000);
     */

     dma_display->fillScreenRGB888(2,0,63);
     //Boldyn B :0
     updatePixel(13, 245, 6, 80);
     delay(100);
     updatePixel(29, 245, 6, 80);
     delay(100);
     updatePixel(45, 245, 6, 80);
     delay(100);
     updatePixel(61, 245, 6, 80);
     delay(100);
     updatePixel(77, 245, 6, 80);
     delay(100);
     updatePixel(93, 245, 6, 80);
     delay(100);
     updatePixel(109, 245, 6, 80);
     delay(100);
     updatePixel(125, 245, 6, 80);
     delay(100);
     updatePixel(141, 245, 6, 80);
     delay(100);
     updatePixel(157, 245, 6, 80);
     delay(100);
     updatePixel(173, 245, 6, 80);
     delay(100);
     updatePixel(189, 245, 6, 80);
     delay(100);
     updatePixel(205, 245, 6, 80);
     delay(100);
     updatePixel(221, 245, 6, 80);
     delay(100);
     updatePixel(237, 245, 6, 80);
     delay(100);
     updatePixel(11, 245, 6, 80);
     delay(100);
     updatePixel(138, 245, 6, 80);
     delay(100);
     updatePixel(13, 245, 6, 80);
     delay(100);
     updatePixel(122, 245, 6, 80);
     delay(100);

     delay(2500);



     for(int i = 0; i<=372 ; i++)
     {
      updatePixel(i, 200, 200, 200);
      delay(10);
     }



    




// ___________________________________________
//|               STATIONS                    |
//|___________________________________________|


    //                METROPOLITAN LINE

    //Amersham
     //updatePixel(0, 255, 133, 3);
     //delay(100);
     //Chesam
     //updatePixel(16, 255, 133, 3);
     //delay(100);
     //Chalfont & Latimer
     //updatePixel(32, 255, 133, 3);
     //delay(100);
     //Chorleywood
     //updatePixel(48, 255, 133, 3);
     //delay(100);
     //Rickmansworth
     //updatePixel(64, 255, 133, 3);
     //delay(100);
     //Croxley
     //updatePixel(18, 255, 133, 3);
     //delay(100);
     //Watford
     //updatePixel(2, 255, 133, 3);
     //delay(100);
     //Moor Park
     //updatePixel(34, 255, 133, 3);
     //delay(100);
     //Northwood
     //updatePixel(50, 255, 133, 3);
     //delay(100);
     //Northwood Hills
     //updatePixel(66, 255, 133, 3);
     //delay(100);
     //Pinner
     //updatePixel(82, 255, 133, 3);
     //delay(100);
     //North Harrow
     //updatePixel(98, 255, 133, 3);
     //delay(100);
     //Harrow-on-the-Hill
     //updatePixel(194, 255, 133, 3);
     //delay(100);
     //Northwick Park
     //updatePixel(210, 255, 133, 3);
     //delay(100);
     //Uxbridge
     //updatePixel(96, 255, 133, 3);
     //delay(100);
     //Hillingdon
     //updatePixel(112, 255, 133, 3);
     //delay(100);
     //Ickenham
     //updatePixel(128, 255, 133, 3);
     //delay(100);
     //Ruislip
     //updatePixel(114, 255, 133, 3);
     //delay(100);
     //Ruislip Manor
     //updatePixel(130, 255, 133, 3);
     //delay(100);
     //Eastcote
     //updatePixel(146, 255, 133, 3);
     //delay(100);
     //Rayners Lane
     //updatePixel(162, 255, 133, 3);
     //delay(100);
     //West Harrow
     //updatePixel(178, 255, 133, 3);
     //delay(100);
     //Preston Road
     //updatePixel(84, 255, 133, 3);
     //delay(100);
     //Wembley Park
     //updatePixel(100, 255, 133, 3);
     //delay(100);
     //Finchley Road
     //updatePixel(212, 255, 133, 3);
     //delay(100);
     //Baker Street - scope
     updatePixel(260, 255, 133, 3);
     delay(100);
     //Great Portland Street - scope
     updatePixel(276, 255, 133, 3);
     delay(100);
     //Euston Square - scope
     updatePixel(292, 255, 133, 3);
     delay(100);
     //King's Cross St. Pancras - scope
     updatePixel(198, 255, 133, 3);
     delay(100);
     //Farringdon
     //updatePixel(215, 255, 133, 3);
     //delay(100);
     //Barbican - scope
     updatePixel(120, 255, 133, 3);
     delay(100);
     //Moorgate - scope
     updatePixel(104, 255, 133, 3);
     delay(100);
     //Liverpool Street - scope
     updatePixel(89, 255, 133, 3);
     delay(100);
     //Aldgate - scope
     updatePixel(121, 255, 133, 3);
     delay(100);


//               ELIZABETH LINE

    //Shenfield Rail Station
     //updatePixel(14, 255, 133, 3);
     //delay(100);
     //Brentwood Rail Station
     //updatePixel(30, 255, 133, 3);
     //delay(100);
     //Harold Wood Rail Station
     //updatePixel(46, 255, 133, 3);
     //delay(100);
     //Gidea Park Rail Station
     //updatePixel(62, 255, 133, 3);
     //delay(100);
     //Romford Rail Station
     //updatePixel(78, 255, 133, 3);
     //delay(100);
     //Chadwell Heath Rail Station
     //updatePixel(94, 255, 133, 3);
     //delay(100);
     //Goodmayes Rail Station
     //updatePixel(110, 255, 133, 3);
     //delay(100);
     //Seven Kings Rail Station
     //updatePixel(126, 255, 133, 3);
     //delay(100);
     //Ilford Rail Station
     //updatePixel(142, 255, 133, 3);
     //delay(100);
     //Manor Park Rail Station
     //updatePixel(158, 255, 133, 3);
     //delay(100);
     //Forest Gate Rail Station
     //updatePixel(174, 255, 133, 3);
     //delay(100);
     //Maryland Rail Station
     //updatePixel(190, 255, 133, 3);
     //delay(100);
     //Stratford
     //updatePixel(285, 255, 133, 3);
     //delay(100);
     //Liverpool Street Rail Station - scope
     updatePixel(73, 0, 255, 0);
     delay(100);
     //Abbey Wood
     //updatePixel(366, 255, 133, 3);
     //delay(100);
     //Woolwich - scope
     updatePixel(350, 255, 133, 3);
     delay(100);
     //Custom House
     //updatePixel(270, 255, 133, 3);
     //delay(100);
     //Canary Wharf - scope
     updatePixel(220, 255, 133, 3);
     delay(100);
     //Whitechapel - scope
     updatePixel(218, 255, 133, 3);
     delay(100);
     //Farringdon crossrail - scope
     updatePixel(231, 0, 255, 0);
     delay(100);
     //Tottenham Court Road - scope
     updatePixel(263, 0, 255, 0);
     delay(100);
     //Bond Street - scope
     updatePixel(278, 0, 255, 0);
     delay(100);
     //Paddington - scope
     updatePixel(340, 255, 133, 3);
     delay(100);
     //Acton Main Line
     //updatePixel(291, 255, 133, 3);
     //delay(100);
     //Ealing Broadway
     //updatePixel(272, 255, 133, 3);
     //delay(100);
     //West Ealing Rail Station
     //updatePixel(304, 255, 133, 3);
     //delay(100);
     //Hanwell Rail Station
     //updatePixel(320, 255, 133, 3);
     //delay(100);
     //Southall Rail Station
     //updatePixel(336, 255, 133, 3);
     //delay(100);
     //Hayes & Harlington Rail Station
     //updatePixel(352, 255, 133, 3);
     //delay(100);
     //West Drayton Rail Station
     //updatePixel(368, 255, 133, 3);
     //delay(100);
     //Iver
     //updatePixel(1, 255, 133, 3);
     //delay(100);
     //Langley
     //updatePixel(17, 255, 133, 3);
     //delay(100);
     //Slough
     //updatePixel(33, 255, 133, 3);
     //delay(100);
     //Burnham
     //updatePixel(49, 255, 133, 3);
     //delay(100);
     //Taplow
     //updatePixel(65, 255, 133, 3);
     //delay(100);
     //Maidenhead
     //updatePixel(81, 255, 133, 3);
     //delay(100);
     //Twyford
     //updatePixel(97, 255, 133, 3);
     //delay(100);
     //Reading
     //updatePixel(113, 255, 133, 3);
     //delay(100);
     //Heathrow Terminals 2 & 3 - scope
     updatePixel(337, 255, 133, 3);
     delay(100);
     //Heathrow Terminal 4 - scope
     updatePixel(369, 255, 133, 3);
     delay(100);
     //Heathrow Terminal 5 - scope
     updatePixel(353, 255, 133, 3);
     delay(100);


//               District Light Railway DLR

     //Beckton - no scope
     //updatePixel(367, 255, 133, 3);
     //delay(100);
     //Gallions Reach
     //updatePixel(351, 255, 133, 3);
     //delay(100);
     //Cyprus
     //updatePixel(335, 255, 133, 3);
     //delay(100);
     //Beckton Park
     //updatePixel(319, 255, 133, 3);
     //delay(100);
     //Royal Albert
     //updatePixel(303, 255, 133, 3);
     //delay(100);
     //Prince Regent
     //updatePixel(287, 255, 133, 3);
     //delay(100);
     //Custom House for ExCel 
     //updatePixel(271, 255, 133, 3);
     //delay(100);
     //Royal Victoria
     //updatePixel(255, 255, 133, 3);
     //delay(100);
     //Woolwich Arsenal - scope
     updatePixel(334, 255, 133, 3);
     delay(100);
     //King George V 
     //updatePixel(318, 255, 133, 3);
     //delay(100);
     //London City Airport
     //updatePixel(302, 255, 133, 3);
     //delay(100);
     //Pontoon Dock
     //updatePixel(286, 255, 133, 3);
     //delay(100);
     //West Silvertown
     //updatePixel(254, 255, 133, 3);
     //delay(100);
     //Canning Town
     //updatePixel(239, 255, 133, 3);
     //delay(100);
     //East India
     //updatePixel(172, 255, 133, 3);
     //delay(100);
     //Blackwall
     //updatePixel(156, 255, 133, 3);
     //delay(100);
     //Poplar
     //updatePixel(140, 255, 133, 3);
     //delay(100);
     //Westferry
     //updatePixel(75, 255, 133, 3);
     //delay(100);
     //Limehouse
     //updatePixel(234, 255, 133, 3);
     //delay(100);
     //Shadwell - scope
     updatePixel(250, 255, 133, 3);
     delay(100);
     //Bank - scope
     updatePixel(137, 255, 133, 3);
     delay(100);
     //Tower Gateway
     //updatePixel(266, 255, 133, 3);
     //delay(100);
     //Star Lane
     //updatePixel(223, 255, 133, 3);
     //delay(100);
     //West Ham
     //updatePixel(207, 255, 133, 3);
     //delay(100);
     //Abbey Road
     //updatePixel(238, 255, 133, 3);
     //delay(100);
     //Stratford High Street
     //updatePixel(222, 255, 133, 3);
     //delay(100);
     //Stratford
     //updatePixel(206, 255, 133, 3);
     //delay(100);
     //Stratford International
     //updatePixel(27, 255, 133, 3);
     //delay(100);
     //West India Quay
     //updatePixel(188, 255, 133, 3);
     //delay(100);
     //Canary Wharf - scope
     updatePixel(204, 0, 255, 0);
     delay(100);
     //Heron Quay
     //updatePixel(349, 255, 133, 3);
     //delay(100);
     //South Quay
     //updatePixel(365, 255, 133, 3);
     //delay(100);
     //Crossharbour
     //updatePixel(252, 255, 133, 3);
     //delay(100);
     //Mudchute
     //updatePixel(268, 255, 133, 3);
     //delay(100);
     //Island Gardens - scope
     updatePixel(284, 255, 133, 3); 
     delay(100);
     //Cutty Sark for Maritime Greenwich - scope
     updatePixel(300, 255, 133, 3);
     delay(100);
     //Greenwich
     //updatePixel(316, 255, 133, 3);
     //delay(100);
     //Deptford Bridge
     //updatePixel(332, 255, 133, 3);
     //delay(100);
     //Elverson Road
     //updatePixel(348, 255, 133, 3);
     //delay(100);
     //Lewisham
     //updatePixel(364, 255, 133, 3);
     //delay(100);
     //All Saints
     //updatePixel(124, 255, 133, 3);
     //delay(100);
     //Langdon Park
     //updatePixel(108, 255, 133, 3);
     //delay(100);
     //Devons Road
     //updatePixel(92, 255, 133, 3);
     //delay(100);
     //Bow Church
     //updatePixel(76, 255, 133, 3);
     //delay(100);
     //Pudding Mill Lane
     //updatePixel(28, 255, 133, 3);
     //delay(100);


//               Central Line

    //West Ruislip
     //updatePixel(80, 255, 133, 3);
     //delay(100);
     //Ruislip Gardens
     //updatePixel(144, 255, 133, 3);
     //delay(100);
     //South Ruislip
     //updatePixel(160, 255, 133, 3);
     //delay(100);
     //Northolt
     //updatePixel(176, 255, 133, 3);
     //delay(100);
     //Greenford
     //updatePixel(192, 255, 133, 3);
     //delay(100);
     //Perivale
     //updatePixel(208, 255, 133, 3);
     //delay(100);
     //Hanger Lane
     //updatePixel(224, 255, 133, 3);
     //delay(100);
     //North Acton
     //updatePixel(323, 255, 133, 3);
     //delay(100);
     //East Acton
     //updatePixel(339, 255, 133, 3);
     //delay(100);
     //West Acton
     //updatePixel(307, 255, 133, 3);
     //delay(100);
     //Ealing Broadway
     //updatePixel(288, 255, 133, 3);
     //delay(100);
     //White City
     //updatePixel(355, 255, 133, 3);
     //delay(100);
     //Shepherd's Bush - scope
     updatePixel(372, 255, 133, 3);
     delay(100);
     //Holland Park - scope
     updatePixel(357, 0, 255, 0);
     delay(100);
     //Notting Hill Gate - scope
     updatePixel(358, 0, 255, 0);
     delay(100);
     //Queensway - scope
     updatePixel(342, 0, 255, 0);
     delay(100);
     //Lancaster Gate - scope
     updatePixel(326, 0, 255, 0);
     delay(100);
     //Marble Arch - scope
     updatePixel(310, 0, 255, 0);
     delay(100);
     //Bond Street - scope
     updatePixel(294, 255, 133, 3);
     delay(100);
     //Oxford Circus - scope
     updatePixel(295, 0, 255, 0);
     delay(100);
     //Tottenham Court Road - scope
     updatePixel(279, 0, 255, 0);
     delay(100);
     //Holborn - scope
     updatePixel(136, 0, 255, 0);
     delay(100);
     //Chancery Lane - scope
     updatePixel(169, 0, 255, 0);
     delay(100);
     //St Paul's - scope
     updatePixel(153, 0, 255, 0);
     delay(100);
     //Bank - scope
     updatePixel(137, 255, 133, 3);
     delay(100);
     //Liverpool Street - scope
     updatePixel(89, 255, 133, 3);
     delay(100);
     //Bethnal Green - scope
     updatePixel(186, 255, 133, 3);
     delay(100);
     //Mile End - scope
     updatePixel(43, 255, 133, 3);
     delay(100);
     //Stratford
     //updatePixel(12, 255, 133, 3);
     //delay(100);
     //Leyton
     //updatePixel(269, 255, 133, 3);
     //delay(100);
     //Leytonstone
     //updatePixel(253, 255, 133, 3);
     //delay(100);
     //Wanstead - scope
     updatePixel(237, 255, 133, 3);
     delay(100);
     //Redbridge - scope
     updatePixel(221, 255, 133, 3);
     delay(100);
     //Gants Hill - scope
     updatePixel(205, 255, 133, 3);
     delay(100);
     //Newbury Park
     //updatePixel(189, 255, 133, 3);
     //delay(100);
     //Barkingside
     //updatePixel(173, 255, 133, 3);
     //delay(100);
     //Fairlop
     //updatePixel(157, 255, 133, 3);
     //delay(100);
     //Hainault
     //updatePixel(141, 255, 133, 3);
     //delay(100);
     //Grange Hill
     //updatePixel(125, 255, 133, 3);
     //delay(100);
     //Chigwell
     //updatePixel(109, 255, 133, 3);
     //delay(100);
     //Roding Valley
     //updatePixel(93, 255, 133, 3);
     //delay(100);
     //Snaresbrook
     //updatePixel(11, 255, 133, 3);
     //delay(100);
     //South Woodford
     //updatePixel(138, 255, 133, 3);
     //delay(100);
     //Woodford
     //updatePixel(122, 255, 133, 3);
     //delay(100);
     //Buckhurts Hill
     //updatePixel(77, 255, 133, 3);
     //delay(100);
     //Loughton
     //updatePixel(61, 255, 133, 3);
     //delay(100);
     //Debden
     //updatePixel(45, 255, 133, 3);
     //delay(100);
     //Theydon Bois
     //updatePixel(29, 255, 133, 3);
     //delay(100);
     //Epping
     //updatePixel(13, 255, 133, 3);
     //delay(100);


//               Bakerloo Line

     //Harrow & Wealdstone
     //updatePixel(290, 255, 133, 3);
     //delay(100);
     //Kenton
     //updatePixel(306, 255, 133, 3);
     //delay(100);
     //South Kenton
     //updatePixel(322, 255, 133, 3);
     //delay(100);
     //North Wembley
     //updatePixel(338, 255, 133, 3);
     //delay(100);
     //Wembley Central
     //updatePixel(354, 255, 133, 3);
     //delay(100);
     //Stonebridge Park
     //updatePixel(370, 255, 133, 3);
     //delay(100);
     //Harlesden
     //updatePixel(3, 255, 133, 3);
     //delay(100);
     //Willesdon Junction
     //updatePixel(19, 255, 133, 3);
     //delay(100);
     //Kensal Green
     //updatePixel(35, 255, 133, 3);
     //delay(100);
     //Queen's Park
     //updatePixel(51, 255, 133, 3);
     //delay(100);
     //Kilburn Park - scope
     updatePixel(67, 255, 133, 3);
     delay(100);
     //Maida Vale - scope
     updatePixel(83, 255, 133, 3);
     delay(100);
     //Warwick Avenue - scope
     updatePixel(99, 255, 133, 3);
     delay(100);
     //Paddington - scope
     updatePixel(115, 255, 133, 3);
     delay(100);
     //Edgware Road - scope
     updatePixel(131, 255, 133, 3);
     delay(100);
     //Marylebone - scope
     updatePixel(147, 255, 133, 3);
     delay(100);
     //Baker Street - scope
     updatePixel(324, 255, 133, 3);
     delay(100);
     //Regent's Park - scope
     updatePixel(308, 255, 133, 3);
     delay(100);
     //Oxford Circus - scope
     updatePixel(295, 0, 255, 0);
     delay(100);
     //Piccadilly Circus - scope
     updatePixel(184, 255, 133, 3);
     delay(100);
     //Charing Cross - scope
     updatePixel(185, 255, 133, 3);
     delay(100);
     //Embankment - scope
     updatePixel(217, 255, 133, 3);
     delay(100);
     //Waterloo - scope
     updatePixel(349, 0, 255, 0);
     delay(100);
     //Lambeth North - scope
     updatePixel(297, 255, 133, 3);
     delay(100);
     //Elephant & Castle - scope
     updatePixel(155, 255, 133, 3);
     delay(100);


//         Northeren Line

     //High Barnet
     //updatePixel(7, 255, 133, 3);
     //delay(100);
     //Totteridge & Whetstone
     //updatePixel(23, 255, 133, 3);
     //delay(100);
     //Woodside Park
     //updatePixel(39, 255, 133, 3);
     //delay(100);
     //West Finchley
     //updatePixel(55, 255, 133, 3);
     //delay(100);
     //Finchley Central
     //updatePixel(87, 255, 133, 3);
     //delay(100);
     //East Finchley
     //updatePixel(103, 255, 133, 3);
     //delay(100);
     //Highgate - scope
     updatePixel(119, 0, 255, 0);
     delay(100);
     //Archway - scope
     updatePixel(135, 0, 255, 0);
     delay(100);
     //Tufnell Park - scope
     updatePixel(151, 0, 255, 0);
     delay(100);
     //Kentish Town - scope
     updatePixel(167, 0, 255, 0);
     delay(100);
     //Camden Town - scope
     updatePixel(150, 0, 255, 0);
     delay(100);
     //Mornington Crescent - scope
     updatePixel(214, 0, 255, 0);
     delay(100);
     //Euston - scope
     updatePixel(230, 0, 255, 0);
     delay(100);
     //King's Cross St Pancras - scope
     updatePixel(182, 255, 133, 3);
     delay(100);
     //Angel - scope
     updatePixel(199, 255, 133, 3);
     delay(100);
     //Old Street - scope
     updatePixel(88, 255, 133, 3);
     delay(100);
     //Moorgate - scope
     updatePixel(104, 255, 133, 3);
     delay(100);
     //Bank - scope
     updatePixel(298, 255, 133, 3);
     delay(100);
     //London Bridge - scope
     updatePixel(123, 255, 133, 3);
     delay(100);
     //Borough - scope
     updatePixel(139, 255, 133, 3);
     delay(100);
     //Elephant & Castle - scope
     updatePixel(155, 255, 133, 3);
     delay(100);
     //Kennington 1 - scope
     updatePixel(171, 255, 133, 3);
     delay(100);
     //Kennington 2 - scope
     updatePixel(313, 255, 133, 3);
     delay(100);
     //Oval - scope
     updatePixel(187, 255, 133, 3);
     delay(100);
     //Stockwell - scope
     updatePixel(203, 255, 133, 3);
     delay(100);
     //Clapham North - scope
     updatePixel(235, 255, 133, 3);
     delay(100);
     //Clapham Common - scope
     updatePixel(251, 255, 133, 3);
     delay(100);
     //Clapham South - scope
     updatePixel(267, 255, 133, 3);
     delay(100);
     //Balham - scope
     updatePixel(283, 255, 133, 3);
     delay(100);
     //Tooting Bec - scope
     updatePixel(299, 255, 133, 3);
     delay(100);
     //Tooting Broadway - scope
     updatePixel(315, 255, 133, 3);
     delay(100);
     //Colliers Wood - scope
     updatePixel(331, 255, 133, 3);
     delay(100);
     //South Wimbledon - scope
     updatePixel(347, 255, 133, 3);
     delay(100);
     //Morden
     //updatePixel(363, 255, 133, 3);
     //delay(100);
     //Mill Hill East
     //updatePixel(71, 255, 133, 3);
     //delay(100);
     //Edgware
     //updatePixel(6, 255, 133, 3);
     //delay(100);
     //Burnt Oak
     //updatePixel(22, 255, 133, 3);
     //delay(100);
     //Colindale
     //updatePixel(38, 255, 133, 3);
     //delay(100);
     //Hendon Central 
     //updatePixel(54, 255, 133, 3);
     //delay(100);
     //Brent Cross
     //updatePixel(70, 255, 133, 3);
     //delay(100);
     //Golders Green
     //updatePixel(86, 255, 133, 3);
     //delay(100);
     //Hampstead - scope
     updatePixel(102, 0, 255, 0);
     delay(100);
     //Belsize Park - scope
     updatePixel(118, 0, 255, 0);
     delay(100);
     //Chalk Farm - scope
     updatePixel(134, 0, 255, 0);
     delay(100);
     //Warren Street - scope
     updatePixel(246, 0, 255, 0);
     delay(100);
     //Goodge Street - scope
     updatePixel(262, 0, 255, 0);
     delay(100);
     //Tottenham Court Road - scope
     updatePixel(279, 0, 255, 0);
     delay(100);
     //Leicester Square - scope
     updatePixel(168, 255, 133, 3);
     delay(100);
     //Charing Cross - scope
     updatePixel(185, 255, 133, 3);
     delay(100);
     //Embankment - scope
     updatePixel(201, 255, 133, 3);
     delay(100);
     //Waterloo - scope
     updatePixel(265, 0, 255, 0);
     delay(100);
     //Nine Elm - scope
     updatePixel(345, 255, 133, 3);
     delay(100);
     //Battersea Power Station - scope
     updatePixel(361, 255, 133, 3);
     delay(100);


//          Circle Line

     //Hamersmith
     //updatePixel(229, 255, 133, 3);
     //delay(100);
     //Goldhawk Road
     //updatePixel(245, 255, 133, 3);
     //delay(100);
     //Shepherd's Bush Market
     //updatePixel(261, 255, 133, 3);
     //delay(100);
     //Wood Lane
    // updatePixel(371, 255, 133, 3);
     //delay(100);
     //Latimer Road
     //updatePixel(275, 255, 133, 3);
     //delay(100);
     //Ladbroke Grove
     //updatePixel(259, 255, 133, 3);
     //delay(100);
     //Westbourne Park
     //updatePixel(243, 255, 133, 3);
     //delay(100);
     //Royal Oak
     //updatePixel(227, 255, 133, 3);
     //delay(100);
     //Paddington - scope
     updatePixel(195, 255, 133, 3);
     delay(100);
     //Edgware Road - scope
     updatePixel(163, 255, 133, 3);
     delay(100);
     //Baker Street - scope
     updatePixel(260, 255, 133, 3);
     delay(100);
     //Great Portland Street - scope
     updatePixel(276, 255, 133, 3);
     delay(100);
     //Euston Square - scope
     updatePixel(292, 255, 133, 3);
     delay(100);
     //King's Cross St. Pancras - scope
     updatePixel(198, 255, 133, 3);
     delay(100);
     //Farringdon
     //updatePixel(215, 255, 133, 3);
     //delay(100);
     //Barbican - scope
     updatePixel(120, 255, 133, 3);
     delay(100);
     //Moorgate - scope
     updatePixel(104, 255, 133, 3);
     delay(100);
     //Liverpool Street - scope
     updatePixel(89, 255, 133, 3);
     delay(100);
     //Aldgate - scope
     updatePixel(121, 255, 133, 3);
     delay(100);
     //Tower Hill - scope
     updatePixel(282, 255, 133, 3);
     delay(100);
     //Monument
     //updatePixel(298, 255, 133, 3);
     //delay(100);
     //Cannon Street - scope
     updatePixel(314, 255, 133, 3);
     delay(100);
     //Paddington(Praed St.) - scope
     updatePixel(211, 255, 133, 3);
     delay(100);
     //Bayswater - scope
     updatePixel(356, 255, 133, 3);
     delay(100);
     //Notting Hill Gate - scope
     updatePixel(358, 0, 255, 0);
     delay(100);
     //High Street Kensington - scope
     updatePixel(341, 255, 133, 3);
     delay(100);
     //Gloucester Road - scope
     updatePixel(296, 255, 133, 3);
     delay(100);
     //South Kensington - scope
     updatePixel(280, 255, 133, 3);
     delay(100);
     //Sloane Sqaure - scope
     updatePixel(264, 255, 133, 3);
     delay(100);
     //Victoria - scope
     updatePixel(232, 255, 133, 3);
     delay(100);
     //St. James Park - scope
     updatePixel(216, 255, 133, 3);
     delay(100);
     //Westminister - scope
     updatePixel(200, 0, 255, 0);
     delay(100); 
     //Embankment - scope
     updatePixel(217, 255, 133, 3);
     delay(100);
     //Temple - scope
     updatePixel(362, 255, 133, 3);
     delay(100);
     //Blackfriars - scope
     updatePixel(346, 255, 133, 3);
     delay(100);
     //Mansion House - scope
     updatePixel(330, 255, 133, 3);
     delay(100);


//          Juiblee

      //Stanmore
      //updatePixel(4, 255, 133, 3);
      //delay(100);
      //Canons Park
      //updatePixel(20, 255, 133, 3);
      //delay(100);
      //Queensbury
      //updatePixel(36, 255, 133, 3);
     // delay(100);
      //Kingsbury
      //updatePixel(52, 255, 133, 3);
      //delay(100);
      //Wembley Park
      //updatePixel(68, 255, 133, 3);
      //delay(100);
      //Neasden
      //updatePixel(116, 255, 133, 3);
      //delay(100);
      //Dollis Hill
      //updatePixel(132, 255, 133, 3);
      //delay(100);
      //Willesden Green
     // updatePixel(148, 255, 133, 3);
      //delay(100);
      //Kilburn 
      //updatePixel(164, 255, 133, 3);
     // delay(100);
      //West Hampstead
      //updatePixel(180, 255, 133, 3);
     // delay(100);
      //Finchley Road
      //updatePixel(196, 255, 133, 3);
      //delay(100);
      //Swiss Cottage - scope
      updatePixel(228, 255, 133, 3);
      delay(100);
      //St. John's Wood - scope
      updatePixel(244, 255, 133, 3);
      delay(100);
      //Baker Street - scope
      updatePixel(324, 255, 133, 3);
      delay(100);
      //Bond Street - scope
      updatePixel(294, 255, 133, 3);
      delay(100);
      //Green Park - scope
      updatePixel(311, 255, 133, 3);
      delay(100);
      //Westminster - scope
      updatePixel(200, 255, 133, 3);
      delay(100);
      //Waterloo - scope
      updatePixel(281, 0, 255, 0);
      delay(100);
      //Southwark - scope
      updatePixel(233, 0, 255, 0);
      delay(100);
      //London Bridge - scope
      updatePixel(123, 255, 133, 3);
      delay(100);
      //Bermondsey - scope
      updatePixel(107, 0, 255, 0);
      delay(100);
      //Canada Water - scope
      updatePixel(91, 0, 255, 0);
      delay(100);
      //Canary Wharf - scope
      updatePixel(236, 0, 255, 0);
      delay(100);
      //North Greenwich - scope
      updatePixel(333, 0, 255, 0);
      delay(100);
      //Canning Town
      //updatePixel(317, 255, 133, 3);
      //delay(100);
      //West Ham
      //updatePixel(301, 255, 133, 3);
      //delay(100);
      //Stratford
      //updatePixel(206, 255, 133, 3);
      //delay(100);


//        Hammersmith & City Line

     //Hammersmith
     //updatePixel(229, 255, 133, 3);
     //delay(100);
     //Goldhawk Road
     //updatePixel(245, 255, 133, 3);
     //delay(100);
     //Shepherd's Bush Market
     //updatePixel(261, 255, 133, 3);
     //delay(100);
     //Wood Lane
     //updatePixel(371, 255, 133, 3);
     //delay(100);
     //Latimer Road
     //updatePixel(275, 255, 133, 3);
    // delay(100);
     //Ladbrooke Grove
     //updatePixel(259, 255, 133, 3);
     //delay(100);
     //Royal Oak
     //updatePixel(227, 255, 133, 3);
     //delay(100);
     //Paddington - scope
     updatePixel(211, 255, 133, 3);
     delay(100);
     //Edgware Road - scope
     updatePixel(163, 255, 133, 3);
     delay(100);
     //Baker Street - scope
     updatePixel(260, 255, 133, 3);
     delay(100);
     //Great Portland Street - scope
     updatePixel(276, 255, 133, 3);
     delay(100);
     //Euston Sqaure - scope
     updatePixel(292, 255, 133, 3);
     delay(100);
     //King's Cross St.Pancras - scope
     updatePixel(198, 255, 133, 3);
     delay(100);
     //Farringdon
     //updatePixel(215, 255, 133, 3);
     //delay(100);
     //Barbican - scope
     updatePixel(120, 255, 133, 3);
     delay(100);
     //Moorgate - scope
     updatePixel(104, 255, 133, 3);
     delay(100);
     //Liverpool Street - scope
     updatePixel(89, 255, 133, 3);
     delay(100);
     //Aldgate East - scope
     updatePixel(105, 255, 133, 3);
     delay(100);
     //Whitechapel - scope
     updatePixel(218, 255, 133, 3);
     delay(100);
     //Stepney Green - scope
     updatePixel(202, 255, 133, 3);
     delay(100);
     //Mile End - scope
     updatePixel(59, 255, 133, 3);
     delay(100);
     //Bow Road - scope
     updatePixel(60, 255, 133, 3);
     delay(100);
     //Bromley by Bow
     //updatePixel(44, 255, 133, 3);
     //delay(100);
     //West Ham
     //updatePixel(207, 255, 133, 3);
     //delay(100);
     //Plaistow
     //updatePixel(191, 255, 133, 3);
     //delay(100);
     //Upton Park
     //updatePixel(175, 255, 133, 3);
     //delay(100);
     //East Ham
     //updatePixel(159, 255, 133, 3);
     //delay(100);
     //Barking
     //updatePixel(143, 255, 133, 3);
     //delay(100);


//             District Line

     //Ealing Broadway
     //updatePixel(288, 255, 133, 3);
     //delay(100);
     //Ealing Common
     //updatePixel(129, 255, 133, 3);
     //delay(100);
     //Acton Town
     //updatePixel(145, 255, 133, 3);
     //delay(100);
     //Chiswick Park
     //updatePixel(161, 255, 133, 3);
     //delay(100);
     //Turnham Green
     //updatePixel(101, 255, 133, 3);
     //delay(100);
     //Stamford Brook
     //updatePixel(133, 255, 133, 3);
     //delay(100);
     //Ravenscourt Park
     //updatePixel(149, 255, 133, 3);
     //delay(100);
     //Hammersmith
     //updatePixel(165, 255, 133, 3);
     //delay(100);
     //Barons Court
     //updatePixel(181, 255, 133, 3);
     //delay(100);
     //West Kensington
     //updatePixel(197, 255, 133, 3);
     //delay(100);
     //Earl's Court - scope
     updatePixel(312, 255, 133, 3);
     delay(100);
     //Gloucester Road - scope
     updatePixel(296, 255, 133, 3);
     delay(100);
     //South Kensington - scope
     updatePixel(280, 255, 133, 3);
     delay(100);
     //Sloane Sqaure - scope
     updatePixel(264, 255, 133, 3);
     delay(100);
     //Victoria - scope
     updatePixel(232, 255, 133, 3);
     delay(100);
     //St. James Park - scope
     updatePixel(216, 255, 133, 3);
     delay(100);
     //Westminister - scope
     updatePixel(200, 0, 255, 0);
     delay(100);
     //Embankment - scope
     updatePixel(217, 255, 133, 3);
     delay(100);
     //Temple - scope
     updatePixel(362, 255, 133, 3);
     delay(100);
     //Blackfriars - scope
     updatePixel(346, 255, 133, 3);
     delay(100);
     //Mansion House - scope
     updatePixel(330, 255, 133, 3);
     delay(100);
     //Cannon Street - scope
     updatePixel(314, 255, 133, 3);
     delay(100);
     //Monument
     //updatePixel(298, 255, 133, 3);
     //delay(100);
     //Tower Hill - scope
     updatePixel(282, 255, 133, 3);
     delay(100);
     //Aldgate East - scope
     updatePixel(105, 255, 133, 3);
     delay(100);
     //Whitechapel - scope
     updatePixel(218, 255, 133, 3);
     delay(100);
     //Stepney Green - scope
     updatePixel(202, 255, 133, 3);
     delay(100);
     //Mile End - scope
     updatePixel(59, 255, 133, 3);
     delay(100);
     //Bow Road - scope
     updatePixel(60, 255, 133, 3);
     delay(100);
     //Bromley-by-Bow
     //updatePixel(44, 255, 133, 3);
     //delay(100);
     //West Ham
     //updatePixel(207, 255, 133, 3);
     //delay(100);
     //Plaistow
     //updatePixel(191, 255, 133, 3);
     //delay(100);
     //Upton Park
     //updatePixel(175, 255, 133, 3);
     //delay(100);
     //East Ham
     //updatePixel(159, 255, 133, 3);
     //delay(100);
     //Barking
     //updatePixel(143, 255, 133, 3);
     //delay(100);
     //Upney
     //updatePixel(127, 255, 133, 3);
     //delay(100);
     //Becontree
     //updatePixel(111, 255, 133, 3);
     //delay(100);
     //Dagenham Heathway
     //updatePixel(95, 255, 133, 3);
     //delay(100);
     //Dagenham East
     //updatePixel(79, 255, 133, 3);
     //delay(100);
     //Elm Park
     //updatePixel(63, 255, 133, 3);
     //delay(100);
     //Hornchurch
     //updatePixel(47, 255, 133, 3);
     //delay(100);
     //Upminster Bridge
     //updatePixel(31, 255, 133, 3);
     //delay(100);
     //Upminster
     //updatePixel(15, 255, 133, 3);
     //delay(100);
     //Richmond
     //updatePixel(85, 255, 133, 3);
     //delay(100);
     //Kew Gardens
     //updatePixel(193, 255, 133, 3);
     //delay(100);
     //Gunnersbury
     //updatePixel(177, 255, 133, 3);
     //delay(100);
     //Wimbledon
     //updatePixel(5, 255, 133, 3);
     //delay(100);
     //Wimbledon Park
     //updatePixel(21, 255, 133, 3);
     //delay(100);
     //Southfields
     //updatePixel(37, 255, 133, 3);
     //delay(100);
     //East Putney
     //updatePixel(53, 255, 133, 3);
     //delay(100);
     //Putney Bridge
     //updatePixel(69, 255, 133, 3);
     //delay(100);
     //Parsons Green
     updatePixel(360, 255, 133, 3);
     delay(100);
     //Fulham Broadway - scope
     updatePixel(344, 255, 133, 3);
     delay(100);
     //West Brompton
     //updatePixel(328, 255, 133, 3);
     //delay(100);
     //Kensington Olympia
     //updatePixel(293, 255, 133, 3);
     //delay(100);
     //High Street Kensington - scope
     updatePixel(343, 255, 133, 3);
     delay(100);
     //Notting Hill Gate - scope
     updatePixel(358, 0, 255, 0);
     delay(100);
     //Bayswater - scope
     updatePixel(356, 255, 133, 3);
     delay(100);
     //Paddington - scope
     updatePixel(195, 255, 133, 3);
     delay(100);
     //Edgware Road - scope
     updatePixel(179, 255, 133, 3);
     delay(100);



//            Picadilly Line

     // Uxbridge
     //updatePixel(96, 255, 133, 3);
     //delay(100);
     //Hillingdon
     //updatePixel(112, 255, 133, 3);
     //delay(100);
     //Ickenham
     //updatePixel(128, 255, 133, 3);
     //delay(100);
     //Ruislip
     //updatePixel(114, 255, 133, 3);
     //delay(100);
     //Ruislip Manor
     //updatePixel(130, 255, 133, 3);
     //delay(100);
     //Eastcote
     //updatePixel(146, 255, 133, 3);
     //delay(100);
     //Rayners Lane
     //updatePixel(162, 255, 133, 3);
     //delay(100);
     //South Harrow
     //updatePixel(226, 255, 133, 3);
     //delay(100);
     //Sudbury Hill
     //updatePixel(242, 255, 133, 3);
     //delay(100);
     //Sudbury Town
     //updatePixel(258, 255, 133, 3);
    // delay(100);
     //Alperton
     //updatePixel(274, 255, 133, 3);
     //delay(100);
     //Park Royal
     //updatePixel(240, 255, 133, 3);
     //delay(100);
     //North Ealing
     //updatePixel(256, 255, 133, 3);
     //delay(100);
     //Ealing Common
     //updatePixel(129, 255, 133, 3);
     //delay(100);
     //Heathrow Terminals 2 & 3 - scope
     updatePixel(137, 255, 133, 3);
     delay(100);
     //Heathrow Terminal 4 - scope
     updatePixel(369, 255, 133, 3);
     delay(100);
     //Heathrow Terminal 5 - scope
     updatePixel(353, 255, 133, 3);
     delay(100);
     //Hatton Cross - scope
     updatePixel(321, 255, 133, 3);
     delay(100);
     //Hounslow West - scope
     updatePixel(305, 255, 133, 3);
     delay(100);
     //Hounslow Central
     //updatePixel(289, 255, 133, 3);
     //delay(100);
     //Hounslow East
     //updatePixel(273, 255, 133, 3);
     //delay(100);
     //Osterley
     //updatePixel(257, 255, 133, 3);
     //delay(100);
     //Boston Manor
     //updatePixel(241, 255, 133, 3);
     //delay(100);
     //Northfields
     //updatePixel(225, 255, 133, 3);
     //delay(100);
     //South Ealing
     //updatePixel(209, 255, 133, 3);
     //delay(100);
     //Acton Town
     //updatePixel(145, 255, 133, 3);
     //delay(100);
     //Turnham Green
     //updatePixel(117, 255, 133, 3);
     //delay(100);
     //Hammersmith
     //updatePixel(213, 255, 133, 3);
     //delay(100);
     //Barons Court
     //updatePixel(277, 255, 133, 3);
     //delay(100);
     //Earl's Court - scope
     updatePixel(309, 255, 133, 3);
     delay(100);
     //Gloucester Road - scope
     updatePixel(325, 255, 133, 3);
     delay(100);
     //South Kensington - scope
     updatePixel(359, 255, 133, 3);
     delay(100);
     //Knightsbridge - scope
     updatePixel(343, 255, 133, 3);
     delay(100);
     //Hyde Park Corner - scope
     updatePixel(327, 255, 133, 3);
     delay(100);
     //Green Park - scope
     updatePixel(311, 255, 133, 3);
     delay(100);
     //Piccadilly Circus - scope
     updatePixel(184, 255, 133, 3);
     delay(100);
     //Leicester Square - scope
     updatePixel(168, 255, 133, 3);
     delay(100);
     //Covent Garden - scope
     updatePixel(152, 255, 133, 3);
     delay(100);
     //Holborn - scope
     updatePixel(136, 0, 255, 0);
     delay(100);
     //Russel Square - scope
     updatePixel(247, 255, 133, 3);
     delay(100);
     //King's Cross St. Pancras - scope
     updatePixel(183, 255, 133, 3);
     delay(100);
     //Caledonian Road - scope
     updatePixel(72, 255, 133, 3);
     delay(100);
     //Holloway Road - scope
     updatePixel(56, 255, 133, 3);
     delay(100);
     //Arsenal - scope
     updatePixel(40, 255, 133, 3);
     delay(100);
     //Finsbury Park - scope
     updatePixel(24, 255, 133, 3);
     delay(100);
     //Manor House - scope
     updatePixel(8, 255, 133, 3);
     delay(100);
     //Turnpike Lane - scope
     updatePixel(106, 255, 133, 3);
     delay(100);
     //Wood Green - scope
     updatePixel(90, 255, 133, 3);
     delay(100);
     //Bounds Green - scope
     updatePixel(74, 255, 133, 3);
     delay(100);
     //Arnos Grove
     //updatePixel(58, 255, 133, 3);
     //delay(100);
     //Southgate - scope
     updatePixel(42, 255, 133, 3);
     delay(100);
     //Oakwood
     //updatePixel(26, 255, 133, 3);
     //delay(100);
     //Cockfosters
     //updatePixel(10, 255, 133, 3);
     //delay(100);


//           Victoria Line

     //Walthamstow Central - scope
     updatePixel(154, 255, 133, 3);
     delay(100);
     //Blackhorse Road - scope
     updatePixel(170, 255, 133, 3);
     delay(100);
     //Tottenham Hale - scope
     updatePixel(9, 255, 133, 3);
     delay(100);
     //Seven Sisters - scope
     updatePixel(25, 255, 133, 3);
     delay(100);
     //Finsbury Park - scope
     updatePixel(41, 255, 133, 3);
     delay(100);
     //Highbury & Islington - scope
     updatePixel(57, 255, 133, 3);
     delay(100);
     //King's Cross * Pancras Int
     //updatePixel(183, 255, 133, 3);
     //delay(100);
     //Euston - scope
     updatePixel(166, 255, 133, 3);
     delay(100);
     //Warren Street - scope
     updatePixel(246, 0, 255, 0);
     delay(100);
     //Oxford Circus - scope
     updatePixel(295, 0, 255, 0);
     delay(100);
     //Green Park - scope
     updatePixel(311, 255, 133, 3);
     delay(100);
     //Victoria - scope
     updatePixel(232, 255, 133, 3);
     delay(100);
     //Pimlico - scope
     updatePixel(248, 255, 133, 3);
     delay(100);
     //Vauxhall - scope
     updatePixel(329, 255, 133, 3);
     delay(100);
     //Stockwell - scope
     updatePixel(203, 255, 133, 3);
     delay(100);
     //Brixton - scope
     updatePixel(219, 255, 133, 3);
     delay(100);


//          Waterloo & City Line

     //Waterloo - scope
     updatePixel(249, 0, 255, 0);
     delay(100);
     //Bank - scope
     updatePixel(137, 255, 133, 3);
     delay(100);


delay(1965000);





  

}

/*
delay(12000); //delays every 2 minutes and then clears screen :)

dma_display->clearScreen();

delay(2000); 

*/

//lights up all the LEDs


    /*
     for(int i = 0; i<=372 ; i++)
     {
      updatePixel(i, 200, 200, 200);
      delay(10);
     }
     */




/*
php code mapping of stations 

$sets = array(
            ['pixel' => 325, 'stop' => '940GZZLUBST', 'line' => 'bakerloo'], //Baker Street
            ['pixel' => 261, 'stop' => '940GZZLUBST', 'line' => 'circle'], //Baker Street
            ['pixel' => 261, 'stop' => '940GZZLUBST', 'line' => 'hammersmith-city'], //Baker Street
            ['pixel' => 325, 'stop' => '940GZZLUBST', 'line' => 'jubilee'], //Baker Street
            ['pixel' => 261, 'stop' => '940GZZLUBST', 'line' => 'metropolitan'], //Baker Street
            ['pixel' => 186, 'stop' => '940GZZLUCHX', 'line' => 'bakerloo'], //Charing Cross
            ['pixel' => 186, 'stop' => '940GZZLUCHX', 'line' => 'northern'], //Charing Cross
            ['pixel' => 156, 'stop' => '940GZZLUEAC', 'line' => 'bakerloo'], //Elephant & Castle
            ['pixel' => 156, 'stop' => '940GZZLUEAC', 'line' => 'northern'], //Elephant & Castle
            ['pixel' => 218, 'stop' => '940GZZLUEMB', 'line' => 'bakerloo'], //Embankment
            ['pixel' => 218, 'stop' => '940GZZLUEMB', 'line' => 'circle'], //Embankment
            ['pixel' => 218, 'stop' => '940GZZLUEMB', 'line' => 'district'], //Embankment
            ['pixel' => 202, 'stop' => '940GZZLUEMB', 'line' => 'northern'], //Embankment
            ['pixel' => 132, 'stop' => '940GZZLUERB', 'line' => 'bakerloo'], //Edgware Road (Bakerloo)
            ['pixel' => 291, 'stop' => '940GZZLUHAW', 'line' => 'bakerloo'], //Harrow & Wealdstone
            ['pixel' => 4, 'stop' => '940GZZLUHSN', 'line' => 'bakerloo'], //Harlesden
            ['pixel' => 307, 'stop' => '940GZZLUKEN', 'line' => 'bakerloo'], //Kenton
            ['pixel' => 68, 'stop' => '940GZZLUKPK', 'line' => 'bakerloo'], //Kilburn Park
            ['pixel' => 36, 'stop' => '940GZZLUKSL', 'line' => 'bakerloo'], //Kensal Green
            ['pixel' => 298, 'stop' => '940GZZLULBN', 'line' => 'bakerloo'], //Lambeth North
            ['pixel' => 84, 'stop' => '940GZZLUMVL', 'line' => 'bakerloo'], //Maida Vale
            ['pixel' => 148, 'stop' => '940GZZLUMYB', 'line' => 'bakerloo'], //Marylebone
            ['pixel' => 339, 'stop' => '940GZZLUNWY', 'line' => 'bakerloo'], //North Wembley
            ['pixel' => 296, 'stop' => '940GZZLUOXC', 'line' => 'bakerloo'], //Oxford Circus
            ['pixel' => 296, 'stop' => '940GZZLUOXC', 'line' => 'central'], //Oxford Circus
            ['pixel' => 296, 'stop' => '940GZZLUOXC', 'line' => 'victoria'], //Oxford Circus
            ['pixel' => 116, 'stop' => '940GZZLUPAC', 'line' => 'bakerloo'], //Paddington
            ['pixel' => 196, 'stop' => '940GZZLUPAC', 'line' => 'circle'], //Paddington
            ['pixel' => 196, 'stop' => '940GZZLUPAC', 'line' => 'district'], //Paddington
            ['pixel' => 185, 'stop' => '940GZZLUPCC', 'line' => 'bakerloo'], //Piccadilly Circus
            ['pixel' => 185, 'stop' => '940GZZLUPCC', 'line' => 'piccadilly'], //Piccadilly Circus
            ['pixel' => 52, 'stop' => '940GZZLUQPS', 'line' => 'bakerloo'], //Queen's Park
            ['pixel' => 309, 'stop' => '940GZZLURGP', 'line' => 'bakerloo'], //Regent's Park
            ['pixel' => 371, 'stop' => '940GZZLUSGP', 'line' => 'bakerloo'], //Stonebridge Park
            ['pixel' => 323, 'stop' => '940GZZLUSKT', 'line' => 'bakerloo'], //South Kenton
            ['pixel' => 20, 'stop' => '940GZZLUWJN', 'line' => 'bakerloo'], //Willesden Junction
            ['pixel' => 100, 'stop' => '940GZZLUWKA', 'line' => 'bakerloo'], //Warwick Avenue
            ['pixel' => 250, 'stop' => '940GZZLUWLO', 'line' => 'bakerloo'], //Waterloo
            ['pixel' => 282, 'stop' => '940GZZLUWLO', 'line' => 'jubilee'], //Waterloo
            ['pixel' => 266, 'stop' => '940GZZLUWLO', 'line' => 'northern'], //Waterloo
            ['pixel' => 250, 'stop' => '940GZZLUWLO', 'line' => 'waterloo-city'], //Waterloo
            ['pixel' => 355, 'stop' => '940GZZLUWYC', 'line' => 'bakerloo'], //Wembley Central
            ['pixel' => 174, 'stop' => '940GZZLUBKE', 'line' => 'central'], //Barkingside
            ['pixel' => 78, 'stop' => '940GZZLUBKH', 'line' => 'central'], //Buckhurst Hill
            ['pixel' => 187, 'stop' => '940GZZLUBLG', 'line' => 'central'], //Bethnal Green
            ['pixel' => 295, 'stop' => '940GZZLUBND', 'line' => 'central'], //Bond Street
            ['pixel' => 295, 'stop' => '940GZZLUBND', 'line' => 'jubilee'], //Bond Street
            ['pixel' => 138, 'stop' => '940GZZLUBNK', 'line' => 'central'], //Bank
            ['pixel' => 299, 'stop' => '940GZZLUBNK', 'line' => 'northern'], //Bank
            ['pixel' => 138, 'stop' => '940GZZLUBNK', 'line' => 'waterloo-city'], //Bank
            ['pixel' => 170, 'stop' => '940GZZLUCHL', 'line' => 'central'], //Chancery Lane
            ['pixel' => 110, 'stop' => '940GZZLUCWL', 'line' => 'central'], //Chigwell
            ['pixel' => 46, 'stop' => '940GZZLUDBN', 'line' => 'central'], //Debden
            ['pixel' => 340, 'stop' => '940GZZLUEAN', 'line' => 'central'], //East Acton
            ['pixel' => 289, 'stop' => '940GZZLUEBY', 'line' => 'central'], //Ealing Broadway
            ['pixel' => 289, 'stop' => '940GZZLUEBY', 'line' => 'district'], //Ealing Broadway
            ['pixel' => 14, 'stop' => '940GZZLUEPG', 'line' => 'central'], //Epping
            ['pixel' => 158, 'stop' => '940GZZLUFLP', 'line' => 'central'], //Fairlop
            ['pixel' => 193, 'stop' => '940GZZLUGFD', 'line' => 'central'], //Greenford
            ['pixel' => 126, 'stop' => '940GZZLUGGH', 'line' => 'central'], //Grange Hill
            ['pixel' => 206, 'stop' => '940GZZLUGTH', 'line' => 'central'], //Gants Hill
            ['pixel' => 137, 'stop' => '940GZZLUHBN', 'line' => 'central'], //Holborn
            ['pixel' => 137, 'stop' => '940GZZLUHBN', 'line' => 'piccadilly'], //Holborn
            ['pixel' => 225, 'stop' => '940GZZLUHGR', 'line' => 'central'], //Hanger Lane
            ['pixel' => 142, 'stop' => '940GZZLUHLT', 'line' => 'central'], //Hainault
            ['pixel' => 358, 'stop' => '940GZZLUHPK', 'line' => 'central'], //Holland Park
            ['pixel' => 62, 'stop' => '940GZZLULGN', 'line' => 'central'], //Loughton
            ['pixel' => 327, 'stop' => '940GZZLULGT', 'line' => 'central'], //Lancaster Gate
            ['pixel' => 90, 'stop' => '940GZZLULVT', 'line' => 'central'], //Liverpool Street
            ['pixel' => 90, 'stop' => '940GZZLULVT', 'line' => 'circle'], //Liverpool Street
            ['pixel' => 90, 'stop' => '940GZZLULVT', 'line' => 'hammersmith-city'], //Liverpool Street
            ['pixel' => 90, 'stop' => '940GZZLULVT', 'line' => 'metropolitan'], //Liverpool Street
            ['pixel' => 270, 'stop' => '940GZZLULYN', 'line' => 'central'], //Leyton
            ['pixel' => 254, 'stop' => '940GZZLULYS', 'line' => 'central'], //Leytonstone
            ['pixel' => 311, 'stop' => '940GZZLUMBA', 'line' => 'central'], //Marble Arch
            ['pixel' => 44, 'stop' => '940GZZLUMED', 'line' => 'central'], //Mile End
            ['pixel' => 60, 'stop' => '940GZZLUMED', 'line' => 'district'], //Mile End
            ['pixel' => 60, 'stop' => '940GZZLUMED', 'line' => 'hammersmith-city'], //Mile End
            ['pixel' => 324, 'stop' => '940GZZLUNAN', 'line' => 'central'], //North Acton
            ['pixel' => 190, 'stop' => '940GZZLUNBP', 'line' => 'central'], //Newbury Park
            ['pixel' => 359, 'stop' => '940GZZLUNHG', 'line' => 'central'], //Notting Hill Gate
            ['pixel' => 359, 'stop' => '940GZZLUNHG', 'line' => 'circle'], //Notting Hill Gate
            ['pixel' => 359, 'stop' => '940GZZLUNHG', 'line' => 'district'], //Notting Hill Gate
            ['pixel' => 177, 'stop' => '940GZZLUNHT', 'line' => 'central'], //Northolt
            ['pixel' => 209, 'stop' => '940GZZLUPVL', 'line' => 'central'], //Perivale
            ['pixel' => 343, 'stop' => '940GZZLUQWY', 'line' => 'central'], //Queensway
            ['pixel' => 222, 'stop' => '940GZZLURBG', 'line' => 'central'], //Redbridge
            ['pixel' => 145, 'stop' => '940GZZLURSG', 'line' => 'central'], //Ruislip Gardens
            ['pixel' => 94, 'stop' => '940GZZLURVY', 'line' => 'central'], //Roding Valley
            ['pixel' => 373, 'stop' => '940GZZLUSBC', 'line' => 'central'], //Shepherd's Bush (Central)
            ['pixel' => 12, 'stop' => '940GZZLUSNB', 'line' => 'central'], //Snaresbrook
            ['pixel' => 154, 'stop' => '940GZZLUSPU', 'line' => 'central'], //St. Paul's
            ['pixel' => 161, 'stop' => '940GZZLUSRP', 'line' => 'central'], //South Ruislip
            ['pixel' => 13, 'stop' => '940GZZLUSTD', 'line' => 'central'], //Stratford
            ['pixel' => 207, 'stop' => '940GZZLUSTD', 'line' => 'jubilee'], //Stratford
            ['pixel' => 139, 'stop' => '940GZZLUSWF', 'line' => 'central'], //South Woodford
            ['pixel' => 280, 'stop' => '940GZZLUTCR', 'line' => 'central'], //Tottenham Court Road
            ['pixel' => 280, 'stop' => '940GZZLUTCR', 'line' => 'northern'], //Tottenham Court Road
            ['pixel' => 30, 'stop' => '940GZZLUTHB', 'line' => 'central'], //Theydon Bois
            ['pixel' => 356, 'stop' => '940GZZLUWCY', 'line' => 'central'], //White City
            ['pixel' => 123, 'stop' => '940GZZLUWOF', 'line' => 'central'], //Woodford
            ['pixel' => 81, 'stop' => '940GZZLUWRP', 'line' => 'central'], //West Ruislip
            ['pixel' => 238, 'stop' => '940GZZLUWSD', 'line' => 'central'], //Wanstead
            ['pixel' => 308, 'stop' => '940GZZLUWTA', 'line' => 'central'], //West Acton
            ['pixel' => 122, 'stop' => '940GZZLUALD', 'line' => 'circle'], //Aldgate
            ['pixel' => 122, 'stop' => '940GZZLUALD', 'line' => 'metropolitan'], //Aldgate
            ['pixel' => 121, 'stop' => '940GZZLUBBN', 'line' => 'circle'], //Barbican
            ['pixel' => 121, 'stop' => '940GZZLUBBN', 'line' => 'hammersmith-city'], //Barbican
            ['pixel' => 121, 'stop' => '940GZZLUBBN', 'line' => 'metropolitan'], //Barbican
            ['pixel' => 347, 'stop' => '940GZZLUBKF', 'line' => 'circle'], //Blackfriars
            ['pixel' => 347, 'stop' => '940GZZLUBKF', 'line' => 'district'], //Blackfriars
            ['pixel' => 357, 'stop' => '940GZZLUBWT', 'line' => 'circle'], //Bayswater
            ['pixel' => 357, 'stop' => '940GZZLUBWT', 'line' => 'district'], //Bayswater
            ['pixel' => 315, 'stop' => '940GZZLUCST', 'line' => 'circle'], //Cannon Street
            ['pixel' => 315, 'stop' => '940GZZLUCST', 'line' => 'district'], //Cannon Street
            ['pixel' => 164, 'stop' => '940GZZLUERC', 'line' => 'circle'], //Edgware Road (Circle Line)
            ['pixel' => 180, 'stop' => '940GZZLUERC', 'line' => 'district'], //Edgware Road (Circle Line)
            ['pixel' => 164, 'stop' => '940GZZLUERC', 'line' => 'hammersmith-city'], //Edgware Road (Circle Line)
            ['pixel' => 293, 'stop' => '940GZZLUESQ', 'line' => 'circle'], //Euston Square
            ['pixel' => 293, 'stop' => '940GZZLUESQ', 'line' => 'hammersmith-city'], //Euston Square
            ['pixel' => 293, 'stop' => '940GZZLUESQ', 'line' => 'metropolitan'], //Euston Square
            ['pixel' => 216, 'stop' => '940GZZLUFCN', 'line' => 'circle'], //Farringdon
            ['pixel' => 216, 'stop' => '940GZZLUFCN', 'line' => 'hammersmith-city'], //Farringdon
            ['pixel' => 216, 'stop' => '940GZZLUFCN', 'line' => 'metropolitan'], //Farringdon
            ['pixel' => 246, 'stop' => '940GZZLUGHK', 'line' => 'circle'], //Goldhawk Road
            ['pixel' => 246, 'stop' => '940GZZLUGHK', 'line' => 'hammersmith-city'], //Goldhawk Road
            ['pixel' => 277, 'stop' => '940GZZLUGPS', 'line' => 'circle'], //Great Portland Street
            ['pixel' => 277, 'stop' => '940GZZLUGPS', 'line' => 'hammersmith-city'], //Great Portland Street
            ['pixel' => 277, 'stop' => '940GZZLUGPS', 'line' => 'metropolitan'], //Great Portland Street
            ['pixel' => 297, 'stop' => '940GZZLUGTR', 'line' => 'circle'], //Gloucester Road
            ['pixel' => 297, 'stop' => '940GZZLUGTR', 'line' => 'district'], //Gloucester Road
            ['pixel' => 326, 'stop' => '940GZZLUGTR', 'line' => 'piccadilly'], //Gloucester Road
            ['pixel' => 230, 'stop' => '940GZZLUHSC', 'line' => 'circle'], //Hammersmith (H&C Line)
            ['pixel' => 230, 'stop' => '940GZZLUHSC', 'line' => 'hammersmith-city'], //Hammersmith (H&C Line)
            ['pixel' => 342, 'stop' => '940GZZLUHSK', 'line' => 'circle'], //High Street Kensington
            ['pixel' => 342, 'stop' => '940GZZLUHSK', 'line' => 'district'], //High Street Kensington
            ['pixel' => 199, 'stop' => '940GZZLUKSX', 'line' => 'circle'], //King's Cross St. Pancras
            ['pixel' => 199, 'stop' => '940GZZLUKSX', 'line' => 'hammersmith-city'], //King's Cross St. Pancras
            ['pixel' => 199, 'stop' => '940GZZLUKSX', 'line' => 'metropolitan'], //King's Cross St. Pancras
            ['pixel' => 183, 'stop' => '940GZZLUKSX', 'line' => 'northern'], //King's Cross St. Pancras
            ['pixel' => 184, 'stop' => '940GZZLUKSX', 'line' => 'piccadilly'], //King's Cross St. Pancras
            ['pixel' => 184, 'stop' => '940GZZLUKSX', 'line' => 'victoria'], //King's Cross St. Pancras
            ['pixel' => 260, 'stop' => '940GZZLULAD', 'line' => 'circle'], //Ladbroke Grove
            ['pixel' => 260, 'stop' => '940GZZLULAD', 'line' => 'hammersmith-city'], //Ladbroke Grove
            ['pixel' => 276, 'stop' => '940GZZLULRD', 'line' => 'circle'], //Latimer Road
            ['pixel' => 276, 'stop' => '940GZZLULRD', 'line' => 'hammersmith-city'], //Latimer Road
            ['pixel' => 105, 'stop' => '940GZZLUMGT', 'line' => 'circle'], //Moorgate
            ['pixel' => 105, 'stop' => '940GZZLUMGT', 'line' => 'hammersmith-city'], //Moorgate
            ['pixel' => 105, 'stop' => '940GZZLUMGT', 'line' => 'metropolitan'], //Moorgate
            ['pixel' => 105, 'stop' => '940GZZLUMGT', 'line' => 'northern'], //Moorgate
            ['pixel' => 299, 'stop' => '940GZZLUMMT', 'line' => 'circle'], //Monument
            ['pixel' => 299, 'stop' => '940GZZLUMMT', 'line' => 'district'], //Monument
            ['pixel' => 331, 'stop' => '940GZZLUMSH', 'line' => 'circle'], //Mansion House
            ['pixel' => 331, 'stop' => '940GZZLUMSH', 'line' => 'district'], //Mansion House
            ['pixel' => 212, 'stop' => '940GZZLUPAH', 'line' => 'circle'], //Paddington (H&C Line)-Underground
            ['pixel' => 212, 'stop' => '940GZZLUPAH', 'line' => 'hammersmith-city'], //Paddington (H&C Line)-Underground
            ['pixel' => 228, 'stop' => '940GZZLURYO', 'line' => 'circle'], //Royal Oak
            ['pixel' => 228, 'stop' => '940GZZLURYO', 'line' => 'hammersmith-city'], //Royal Oak
            ['pixel' => 262, 'stop' => '940GZZLUSBM', 'line' => 'circle'], //Shepherd's Bush Market
            ['pixel' => 262, 'stop' => '940GZZLUSBM', 'line' => 'hammersmith-city'], //Shepherd's Bush Market
            ['pixel' => 217, 'stop' => '940GZZLUSJP', 'line' => 'circle'], //St. James's Park
            ['pixel' => 217, 'stop' => '940GZZLUSJP', 'line' => 'district'], //St. James's Park
            ['pixel' => 281, 'stop' => '940GZZLUSKS', 'line' => 'circle'], //South Kensington
            ['pixel' => 281, 'stop' => '940GZZLUSKS', 'line' => 'district'], //South Kensington
            ['pixel' => 360, 'stop' => '940GZZLUSKS', 'line' => 'piccadilly'], //South Kensington
            ['pixel' => 265, 'stop' => '940GZZLUSSQ', 'line' => 'circle'], //Sloane Square
            ['pixel' => 265, 'stop' => '940GZZLUSSQ', 'line' => 'district'], //Sloane Square
            ['pixel' => 363, 'stop' => '940GZZLUTMP', 'line' => 'circle'], //Temple
            ['pixel' => 363, 'stop' => '940GZZLUTMP', 'line' => 'district'], //Temple
            ['pixel' => 283, 'stop' => '940GZZLUTWH', 'line' => 'circle'], //Tower Hill
            ['pixel' => 283, 'stop' => '940GZZLUTWH', 'line' => 'district'], //Tower Hill
            ['pixel' => 233, 'stop' => '940GZZLUVIC', 'line' => 'circle'], //Victoria
            ['pixel' => 233, 'stop' => '940GZZLUVIC', 'line' => 'district'], //Victoria
            ['pixel' => 233, 'stop' => '940GZZLUVIC', 'line' => 'victoria'], //Victoria
            ['pixel' => 372, 'stop' => '940GZZLUWLA', 'line' => 'circle'], //Wood Lane
            ['pixel' => 372, 'stop' => '940GZZLUWLA', 'line' => 'hammersmith-city'], //Wood Lane
            ['pixel' => 201, 'stop' => '940GZZLUWSM', 'line' => 'circle'], //Westminster
            ['pixel' => 201, 'stop' => '940GZZLUWSM', 'line' => 'district'], //Westminster
            ['pixel' => 201, 'stop' => '940GZZLUWSM', 'line' => 'jubilee'], //Westminster
            ['pixel' => 244, 'stop' => '940GZZLUWSP', 'line' => 'circle'], //Westbourne Park
            ['pixel' => 244, 'stop' => '940GZZLUWSP', 'line' => 'hammersmith-city'], //Westbourne Park
            ['pixel' => 146, 'stop' => '940GZZLUACT', 'line' => 'district'], //Acton Town
            ['pixel' => 146, 'stop' => '940GZZLUACT', 'line' => 'piccadilly'], //Acton Town
            ['pixel' => 106, 'stop' => '940GZZLUADE', 'line' => 'district'], //Aldgate East
            ['pixel' => 106, 'stop' => '940GZZLUADE', 'line' => 'hammersmith-city'], //Aldgate East
            ['pixel' => 45, 'stop' => '940GZZLUBBB', 'line' => 'district'], //Bromley-by-Bow
            ['pixel' => 45, 'stop' => '940GZZLUBBB', 'line' => 'hammersmith-city'], //Bromley-by-Bow
            ['pixel' => 112, 'stop' => '940GZZLUBEC', 'line' => 'district'], //Becontree
            ['pixel' => 144, 'stop' => '940GZZLUBKG', 'line' => 'district'], //Barking
            ['pixel' => 144, 'stop' => '940GZZLUBKG', 'line' => 'hammersmith-city'], //Barking
            ['pixel' => 182, 'stop' => '940GZZLUBSC', 'line' => 'district'], //Barons Court
            ['pixel' => 278, 'stop' => '940GZZLUBSC', 'line' => 'piccadilly'], //Barons Court
            ['pixel' => 61, 'stop' => '940GZZLUBWR', 'line' => 'district'], //Bow Road
            ['pixel' => 61, 'stop' => '940GZZLUBWR', 'line' => 'hammersmith-city'], //Bow Road
            ['pixel' => 162, 'stop' => '940GZZLUCWP', 'line' => 'district'], //Chiswick Park
            ['pixel' => 80, 'stop' => '940GZZLUDGE', 'line' => 'district'], //Dagenham East
            ['pixel' => 96, 'stop' => '940GZZLUDGY', 'line' => 'district'], //Dagenham Heathway
            ['pixel' => 130, 'stop' => '940GZZLUECM', 'line' => 'district'], //Ealing Common
            ['pixel' => 130, 'stop' => '940GZZLUECM', 'line' => 'piccadilly'], //Ealing Common
            ['pixel' => 313, 'stop' => '940GZZLUECT', 'line' => 'district'], //Earl's Court
            ['pixel' => 310, 'stop' => '940GZZLUECT', 'line' => 'piccadilly'], //Earl's Court
            ['pixel' => 160, 'stop' => '940GZZLUEHM', 'line' => 'district'], //East Ham
            ['pixel' => 160, 'stop' => '940GZZLUEHM', 'line' => 'hammersmith-city'], //East Ham
            ['pixel' => 64, 'stop' => '940GZZLUEPK', 'line' => 'district'], //Elm Park
            ['pixel' => 54, 'stop' => '940GZZLUEPY', 'line' => 'district'], //East Putney
            ['pixel' => 345, 'stop' => '940GZZLUFBY', 'line' => 'district'], //Fulham Broadway
            ['pixel' => 178, 'stop' => '940GZZLUGBY', 'line' => 'district'], //Gunnersbury
            ['pixel' => 48, 'stop' => '940GZZLUHCH', 'line' => 'district'], //Hornchurch
            ['pixel' => 166, 'stop' => '940GZZLUHSD', 'line' => 'district'], //Hammersmith (Dist&Picc Line)
            ['pixel' => 214, 'stop' => '940GZZLUHSD', 'line' => 'piccadilly'], //Hammersmith (Dist&Picc Line)
            ['pixel' => 294, 'stop' => '940GZZLUKOY', 'line' => 'district'], //Kensington (Olympia)
            ['pixel' => 194, 'stop' => '940GZZLUKWG', 'line' => 'district'], //Kew Gardens
            ['pixel' => 192, 'stop' => '940GZZLUPLW', 'line' => 'district'], //Plaistow
            ['pixel' => 192, 'stop' => '940GZZLUPLW', 'line' => 'hammersmith-city'], //Plaistow
            ['pixel' => 361, 'stop' => '940GZZLUPSG', 'line' => 'district'], //Parsons Green
            ['pixel' => 70, 'stop' => '940GZZLUPYB', 'line' => 'district'], //Putney Bridge
            ['pixel' => 86, 'stop' => '940GZZLURMD', 'line' => 'district'], //Richmond
            ['pixel' => 150, 'stop' => '940GZZLURVP', 'line' => 'district'], //Ravenscourt Park
            ['pixel' => 134, 'stop' => '940GZZLUSFB', 'line' => 'district'], //Stamford Brook
            ['pixel' => 38, 'stop' => '940GZZLUSFS', 'line' => 'district'], //Southfields
            ['pixel' => 203, 'stop' => '940GZZLUSGN', 'line' => 'district'], //Stepney Green
            ['pixel' => 203, 'stop' => '940GZZLUSGN', 'line' => 'hammersmith-city'], //Stepney Green
            ['pixel' => 102, 'stop' => '940GZZLUTNG', 'line' => 'district'], //Turnham Green
            ['pixel' => 118, 'stop' => '940GZZLUTNG', 'line' => 'piccadilly'], //Turnham Green
            ['pixel' => 32, 'stop' => '940GZZLUUPB', 'line' => 'district'], //Upminster Bridge
            ['pixel' => 176, 'stop' => '940GZZLUUPK', 'line' => 'district'], //Upton Park
            ['pixel' => 176, 'stop' => '940GZZLUUPK', 'line' => 'hammersmith-city'], //Upton Park
            ['pixel' => 16, 'stop' => '940GZZLUUPM', 'line' => 'district'], //Upminster
            ['pixel' => 128, 'stop' => '940GZZLUUPY', 'line' => 'district'], //Upney
            ['pixel' => 329, 'stop' => '940GZZLUWBN', 'line' => 'district'], //West Brompton
            ['pixel' => 208, 'stop' => '940GZZLUWHM', 'line' => 'district'], //West Ham
            ['pixel' => 208, 'stop' => '940GZZLUWHM', 'line' => 'hammersmith-city'], //West Ham
            ['pixel' => 302, 'stop' => '940GZZLUWHM', 'line' => 'jubilee'], //West Ham
            ['pixel' => 6, 'stop' => '940GZZLUWIM', 'line' => 'district'], //Wimbledon
            ['pixel' => 22, 'stop' => '940GZZLUWIP', 'line' => 'district'], //Wimbledon Park
            ['pixel' => 198, 'stop' => '940GZZLUWKN', 'line' => 'district'], //West Kensington
            ['pixel' => 219, 'stop' => '940GZZLUWPL', 'line' => 'district'], //Whitechapel
            ['pixel' => 219, 'stop' => '940GZZLUWPL', 'line' => 'hammersmith-city'], //Whitechapel
            ['pixel' => 239, 'stop' => '940GZZDLABR', 'line' => 'dlr'], //Abbey Road
            ['pixel' => 125, 'stop' => '940GZZDLALL', 'line' => 'dlr'], //All Saints
            ['pixel' => 368, 'stop' => '940GZZDLBEC', 'line' => 'dlr'], //Beckton
            ['pixel' => 157, 'stop' => '940GZZDLBLA', 'line' => 'dlr'], //Blackwall
            ['pixel' => 138, 'stop' => '940GZZDLBNK', 'line' => 'dlr'], //Bank
            ['pixel' => 77, 'stop' => '940GZZDLBOW', 'line' => 'dlr'], //Bow Church
            ['pixel' => 320, 'stop' => '940GZZDLBPK', 'line' => 'dlr'], //Beckton Park
            ['pixel' => 205, 'stop' => '940GZZDLCAN', 'line' => 'dlr'], //Canary Wharf
            ['pixel' => 240, 'stop' => '940GZZDLCGT', 'line' => 'dlr'], //Canning Town
            ['pixel' => 253, 'stop' => '940GZZDLCLA', 'line' => 'dlr'], //Crossharbour
            ['pixel' => 272, 'stop' => '940GZZDLCUS', 'line' => 'dlr'], //Custom House (for ExCel)
            ['pixel' => 301, 'stop' => '940GZZDLCUT', 'line' => 'dlr'], //Cutty Sark (for Maritime Greenwich)
            ['pixel' => 336, 'stop' => '940GZZDLCYP', 'line' => 'dlr'], //Cyprus
            ['pixel' => 333, 'stop' => '940GZZDLDEP', 'line' => 'dlr'], //Deptford Bridge
            ['pixel' => 93, 'stop' => '940GZZDLDEV', 'line' => 'dlr'], //Devons Road
            ['pixel' => 173, 'stop' => '940GZZDLEIN', 'line' => 'dlr'], //East India
            ['pixel' => 349, 'stop' => '940GZZDLELV', 'line' => 'dlr'], //Elverson Road
            ['pixel' => 352, 'stop' => '940GZZDLGAL', 'line' => 'dlr'], //Gallions Reach
            ['pixel' => 317, 'stop' => '940GZZDLGRE', 'line' => 'dlr'], //Greenwich
            ['pixel' => 350, 'stop' => '940GZZDLHEQ', 'line' => 'dlr'], //Heron Quays
            ['pixel' => 285, 'stop' => '940GZZDLISL', 'line' => 'dlr'], //Island Gardens
            ['pixel' => 319, 'stop' => '940GZZDLKGV', 'line' => 'dlr'], //King George V
            ['pixel' => 303, 'stop' => '940GZZDLLCA', 'line' => 'dlr'], //London City Airport
            ['pixel' => 109, 'stop' => '940GZZDLLDP', 'line' => 'dlr'], //Langdon Park
            ['pixel' => 365, 'stop' => '940GZZDLLEW', 'line' => 'dlr'], //Lewisham
            ['pixel' => 235, 'stop' => '940GZZDLLIM', 'line' => 'dlr'], //Limehouse
            ['pixel' => 269, 'stop' => '940GZZDLMUD', 'line' => 'dlr'], //Mudchute
            ['pixel' => 287, 'stop' => '940GZZDLPDK', 'line' => 'dlr'], //Pontoon Dock
            ['pixel' => 141, 'stop' => '940GZZDLPOP', 'line' => 'dlr'], //Poplar
            ['pixel' => 288, 'stop' => '940GZZDLPRE', 'line' => 'dlr'], //Prince Regent
            ['pixel' => 29, 'stop' => '940GZZDLPUD', 'line' => 'dlr'], //Pudding Mill Lane
            ['pixel' => 304, 'stop' => '940GZZDLRAL', 'line' => 'dlr'], //Royal Albert
            ['pixel' => 256, 'stop' => '940GZZDLRVC', 'line' => 'dlr'], //Royal Victoria
            ['pixel' => 251, 'stop' => '940GZZDLSHA', 'line' => 'dlr'], //Shadwell
            ['pixel' => 223, 'stop' => '940GZZDLSHS', 'line' => 'dlr'], //Stratford High Street
            ['pixel' => 28, 'stop' => '940GZZDLSIT', 'line' => 'dlr'], //Stratford International
            ['pixel' => 366, 'stop' => '940GZZDLSOQ', 'line' => 'dlr'], //South Quay
            ['pixel' => 207, 'stop' => '940GZZDLSTD', 'line' => 'dlr'], //Stratford
            ['pixel' => 224, 'stop' => '940GZZDLSTL', 'line' => 'dlr'], //Star Lane
            ['pixel' => 267, 'stop' => '940GZZDLTWG', 'line' => 'dlr'], //Tower Gateway
            ['pixel' => 76, 'stop' => '940GZZDLWFE', 'line' => 'dlr'], //Westferry
            ['pixel' => 208, 'stop' => '940GZZDLWHM', 'line' => 'dlr'], //West Ham
            ['pixel' => 189, 'stop' => '940GZZDLWIQ', 'line' => 'dlr'], //West India Quay
            ['pixel' => 335, 'stop' => '940GZZDLWLA', 'line' => 'dlr'], //Woolwich Arsenal
            ['pixel' => 255, 'stop' => '940GZZDLWSV', 'line' => 'dlr'], //West Silvertown
            ['pixel' => 367, 'stop' => '910GABWDXR', 'line' => 'elizabeth'], //Abbey Wood
            ['pixel' => 292, 'stop' => '910GACTONML', 'line' => 'elizabeth'], //Acton Main Line Rail Station
            ['pixel' => 50, 'stop' => '910GBNHAM', 'line' => 'elizabeth'], //Burnham (Berks) Rail Station
            ['pixel' => 31, 'stop' => '910GBRTWOOD', 'line' => 'elizabeth'], //Brentwood Rail Station
            ['pixel' => 221, 'stop' => '910GCANWHRF', 'line' => 'elizabeth'], //Canary Wharf
            ['pixel' => 95, 'stop' => '910GCHDWLHT', 'line' => 'elizabeth'], //Chadwell Heath Rail Station
            ['pixel' => 271, 'stop' => '910GCSTMHSXR', 'line' => 'elizabeth'], //Custom House
            ['pixel' => 273, 'stop' => '910GEALINGB', 'line' => 'elizabeth'], //Ealing Broadway Rail Station
            ['pixel' => 232, 'stop' => '910GFRNDXR', 'line' => 'elizabeth'], //Farringdon
            ['pixel' => 175, 'stop' => '910GFRSTGT', 'line' => 'elizabeth'], //Forest Gate Rail Station
            ['pixel' => 63, 'stop' => '910GGIDEAPK', 'line' => 'elizabeth'], //Gidea Park Rail Station
            ['pixel' => 111, 'stop' => '910GGODMAYS', 'line' => 'elizabeth'], //Goodmayes Rail Station
            ['pixel' => 321, 'stop' => '910GHANWELL', 'line' => 'elizabeth'], //Hanwell Rail Station
            ['pixel' => 353, 'stop' => '910GHAYESAH', 'line' => 'elizabeth'], //Hayes & Harlington Rail Station
            ['pixel' => 47, 'stop' => '910GHRLDWOD', 'line' => 'elizabeth'], //Harold Wood Rail Station
            ['pixel' => 338, 'stop' => '910GHTRWAPT', 'line' => 'elizabeth'], //Heathrow Terminals 2 & 3 Rail Station
            ['pixel' => 370, 'stop' => '910GHTRWTM4', 'line' => 'elizabeth'], //Heathrow Terminal 4 Rail Station
            ['pixel' => 354, 'stop' => '910GHTRWTM5', 'line' => 'elizabeth'], //Heathrow Terminal 5 Rail Station
            ['pixel' => 143, 'stop' => '910GILFORD', 'line' => 'elizabeth'], //Ilford Rail Station
            ['pixel' => 2, 'stop' => '910GIVER', 'line' => 'elizabeth'], //Iver Rail Station
            ['pixel' => 18, 'stop' => '910GLANGLEY', 'line' => 'elizabeth'], //Langley (Berks) Rail Station
            ['pixel' => 74, 'stop' => '910GLIVST', 'line' => 'elizabeth'], //London Liverpool Street Rail Station
            ['pixel' => 74, 'stop' => '910GLIVSTLL', 'line' => 'elizabeth'], //Liverpool Street
            ['pixel' => 159, 'stop' => '910GMANRPK', 'line' => 'elizabeth'], //Manor Park Rail Station
            ['pixel' => 82, 'stop' => '910GMDNHEAD', 'line' => 'elizabeth'], //Maidenhead Rail Station
            ['pixel' => 191, 'stop' => '910GMRYLAND', 'line' => 'elizabeth'], //Maryland Rail Station
            ['pixel' => 341, 'stop' => '910GPADTLL', 'line' => 'elizabeth'], //Paddington
            ['pixel' => 341, 'stop' => '910GPADTON', 'line' => 'elizabeth'], //London Paddington Rail Station
            ['pixel' => 114, 'stop' => '910GRDNGSTN', 'line' => 'elizabeth'], //Reading Rail Station
            ['pixel' => 79, 'stop' => '910GROMFORD', 'line' => 'elizabeth'], //Romford Rail Station
            ['pixel' => 15, 'stop' => '910GSHENFLD', 'line' => 'elizabeth'], //Shenfield Rail Station
            ['pixel' => 34, 'stop' => '910GSLOUGH', 'line' => 'elizabeth'], //Slough Rail Station
            ['pixel' => 286, 'stop' => '910GSTFD', 'line' => 'elizabeth'], //Stratford (London) Rail Station
            ['pixel' => 337, 'stop' => '910GSTHALL', 'line' => 'elizabeth'], //Southall Rail Station
            ['pixel' => 127, 'stop' => '910GSVNKNGS', 'line' => 'elizabeth'], //Seven Kings Rail Station
            ['pixel' => 66, 'stop' => '910GTAPLOW', 'line' => 'elizabeth'], //Taplow Rail Station
            ['pixel' => 264, 'stop' => '910GTOTCTRD', 'line' => 'elizabeth'], //Tottenham Court Road
            ['pixel' => 98, 'stop' => '910GTWYFORD', 'line' => 'elizabeth'], //Twyford Rail Station
            ['pixel' => 219, 'stop' => '910GWCHAPXR', 'line' => 'elizabeth'], //Whitechapel
            ['pixel' => 369, 'stop' => '910GWDRYTON', 'line' => 'elizabeth'], //West Drayton Rail Station
            ['pixel' => 305, 'stop' => '910GWEALING', 'line' => 'elizabeth'], //West Ealing Rail Station
            ['pixel' => 351, 'stop' => '910GWOLWXR', 'line' => 'elizabeth'], //Woolwich
            ['pixel' => 108, 'stop' => '940GZZLUBMY', 'line' => 'jubilee'], //Bermondsey
            ['pixel' => 318, 'stop' => '940GZZLUCGT', 'line' => 'jubilee'], //Canning Town
            ['pixel' => 21, 'stop' => '940GZZLUCPK', 'line' => 'jubilee'], //Canons Park
            ['pixel' => 92, 'stop' => '940GZZLUCWR', 'line' => 'jubilee'], //Canada Water
            ['pixel' => 237, 'stop' => '940GZZLUCYF', 'line' => 'jubilee'], //Canary Wharf
            ['pixel' => 133, 'stop' => '940GZZLUDOH', 'line' => 'jubilee'], //Dollis Hill
            ['pixel' => 197, 'stop' => '940GZZLUFYR', 'line' => 'jubilee'], //Finchley Road
            ['pixel' => 213, 'stop' => '940GZZLUFYR', 'line' => 'metropolitan'], //Finchley Road
            ['pixel' => 312, 'stop' => '940GZZLUGPK', 'line' => 'jubilee'], //Green Park
            ['pixel' => 312, 'stop' => '940GZZLUGPK', 'line' => 'piccadilly'], //Green Park
            ['pixel' => 312, 'stop' => '940GZZLUGPK', 'line' => 'victoria'], //Green Park
            ['pixel' => 165, 'stop' => '940GZZLUKBN', 'line' => 'jubilee'], //Kilburn
            ['pixel' => 53, 'stop' => '940GZZLUKBY', 'line' => 'jubilee'], //Kingsbury
            ['pixel' => 124, 'stop' => '940GZZLULNB', 'line' => 'jubilee'], //London Bridge
            ['pixel' => 124, 'stop' => '940GZZLULNB', 'line' => 'northern'], //London Bridge
            ['pixel' => 117, 'stop' => '940GZZLUNDN', 'line' => 'jubilee'], //Neasden
            ['pixel' => 334, 'stop' => '940GZZLUNGW', 'line' => 'jubilee'], //North Greenwich
            ['pixel' => 37, 'stop' => '940GZZLUQBY', 'line' => 'jubilee'], //Queensbury
            ['pixel' => 245, 'stop' => '940GZZLUSJW', 'line' => 'jubilee'], //St. John's Wood
            ['pixel' => 5, 'stop' => '940GZZLUSTM', 'line' => 'jubilee'], //Stanmore
            ['pixel' => 229, 'stop' => '940GZZLUSWC', 'line' => 'jubilee'], //Swiss Cottage
            ['pixel' => 234, 'stop' => '940GZZLUSWK', 'line' => 'jubilee'], //Southwark
            ['pixel' => 181, 'stop' => '940GZZLUWHP', 'line' => 'jubilee'], //West Hampstead
            ['pixel' => 149, 'stop' => '940GZZLUWIG', 'line' => 'jubilee'], //Willesden Green
            ['pixel' => 9999, 'stop' => '940GZZLUWIG', 'line' => 'metropolitan'], //Willesden Green
            ['pixel' => 69, 'stop' => '940GZZLUWYP', 'line' => 'jubilee'], //Wembley Park
            ['pixel' => 101, 'stop' => '940GZZLUWYP', 'line' => 'metropolitan'], //Wembley Park
            ['pixel' => 1, 'stop' => '940GZZLUAMS', 'line' => 'metropolitan'], //Amersham 
            ['pixel' => 33, 'stop' => '940GZZLUCAL', 'line' => 'metropolitan'], //Chalfont & Latimer
            ['pixel' => 17, 'stop' => '940GZZLUCSM', 'line' => 'metropolitan'], //Chesham
            ['pixel' => 19, 'stop' => '940GZZLUCXY', 'line' => 'metropolitan'], //Croxley
            ['pixel' => 49, 'stop' => '940GZZLUCYD', 'line' => 'metropolitan'], //Chorleywood
            ['pixel' => 147, 'stop' => '940GZZLUEAE', 'line' => 'metropolitan'], //Eastcote
            ['pixel' => 147, 'stop' => '940GZZLUEAE', 'line' => 'piccadilly'], //Eastcote
            ['pixel' => 113, 'stop' => '940GZZLUHGD', 'line' => 'metropolitan'], //Hillingdon
            ['pixel' => 113, 'stop' => '940GZZLUHGD', 'line' => 'piccadilly'], //Hillingdon
            ['pixel' => 195, 'stop' => '940GZZLUHOH', 'line' => 'metropolitan'], //Harrow-on-the-Hill
            ['pixel' => 129, 'stop' => '940GZZLUICK', 'line' => 'metropolitan'], //Ickenham
            ['pixel' => 129, 'stop' => '940GZZLUICK', 'line' => 'piccadilly'], //Ickenham
            ['pixel' => 35, 'stop' => '940GZZLUMPK', 'line' => 'metropolitan'], //Moor Park
            ['pixel' => 99, 'stop' => '940GZZLUNHA', 'line' => 'metropolitan'], //North Harrow
            ['pixel' => 211, 'stop' => '940GZZLUNKP', 'line' => 'metropolitan'], //Northwick Park
            ['pixel' => 51, 'stop' => '940GZZLUNOW', 'line' => 'metropolitan'], //Northwood
            ['pixel' => 67, 'stop' => '940GZZLUNWH', 'line' => 'metropolitan'], //Northwood Hills
            ['pixel' => 83, 'stop' => '940GZZLUPNR', 'line' => 'metropolitan'], //Pinner
            ['pixel' => 85, 'stop' => '940GZZLUPRD', 'line' => 'metropolitan'], //Preston Road
            ['pixel' => 65, 'stop' => '940GZZLURKW', 'line' => 'metropolitan'], //Rickmansworth
            ['pixel' => 131, 'stop' => '940GZZLURSM', 'line' => 'metropolitan'], //Ruislip Manor
            ['pixel' => 131, 'stop' => '940GZZLURSM', 'line' => 'piccadilly'], //Ruislip Manor
            ['pixel' => 115, 'stop' => '940GZZLURSP', 'line' => 'metropolitan'], //Ruislip
            ['pixel' => 115, 'stop' => '940GZZLURSP', 'line' => 'piccadilly'], //Ruislip
            ['pixel' => 163, 'stop' => '940GZZLURYL', 'line' => 'metropolitan'], //Rayners Lane
            ['pixel' => 163, 'stop' => '940GZZLURYL', 'line' => 'piccadilly'], //Rayners Lane
            ['pixel' => 97, 'stop' => '940GZZLUUXB', 'line' => 'metropolitan'], //Uxbridge
            ['pixel' => 97, 'stop' => '940GZZLUUXB', 'line' => 'piccadilly'], //Uxbridge
            ['pixel' => 3, 'stop' => '940GZZLUWAF', 'line' => 'metropolitan'], //Watford
            ['pixel' => 179, 'stop' => '940GZZLUWHW', 'line' => 'metropolitan'], //West Harrow
            ['pixel' => 362, 'stop' => '940GZZBPSUST', 'line' => 'northern'], //Battersea Power Station
            ['pixel' => 136, 'stop' => '940GZZLUACY', 'line' => 'northern'], //Archway
            ['pixel' => 200, 'stop' => '940GZZLUAGL', 'line' => 'northern'], //Angel
            ['pixel' => 284, 'stop' => '940GZZLUBLM', 'line' => 'northern'], //Balham
            ['pixel' => 140, 'stop' => '940GZZLUBOR', 'line' => 'northern'], //Borough
            ['pixel' => 23, 'stop' => '940GZZLUBTK', 'line' => 'northern'], //Burnt Oak
            ['pixel' => 71, 'stop' => '940GZZLUBTX', 'line' => 'northern'], //Brent Cross
            ['pixel' => 119, 'stop' => '940GZZLUBZP', 'line' => 'northern'], //Belsize Park
            ['pixel' => 135, 'stop' => '940GZZLUCFM', 'line' => 'northern'], //Chalk Farm
            ['pixel' => 39, 'stop' => '940GZZLUCND', 'line' => 'northern'], //Colindale
            ['pixel' => 252, 'stop' => '940GZZLUCPC', 'line' => 'northern'], //Clapham Common
            ['pixel' => 236, 'stop' => '940GZZLUCPN', 'line' => 'northern'], //Clapham North
            ['pixel' => 268, 'stop' => '940GZZLUCPS', 'line' => 'northern'], //Clapham South
            ['pixel' => 332, 'stop' => '940GZZLUCSD', 'line' => 'northern'], //Colliers Wood
            ['pixel' => 151, 'stop' => '940GZZLUCTN', 'line' => 'northern'], //Camden Town
            ['pixel' => 104, 'stop' => '940GZZLUEFY', 'line' => 'northern'], //East Finchley
            ['pixel' => 7, 'stop' => '940GZZLUEGW', 'line' => 'northern'], //Edgware
            ['pixel' => 231, 'stop' => '940GZZLUEUS', 'line' => 'northern'], //Euston
            ['pixel' => 167, 'stop' => '940GZZLUEUS', 'line' => 'victoria'], //Euston
            ['pixel' => 88, 'stop' => '940GZZLUFYC', 'line' => 'northern'], //Finchley Central
            ['pixel' => 263, 'stop' => '940GZZLUGDG', 'line' => 'northern'], //Goodge Street
            ['pixel' => 87, 'stop' => '940GZZLUGGN', 'line' => 'northern'], //Golders Green
            ['pixel' => 8, 'stop' => '940GZZLUHBT', 'line' => 'northern'], //High Barnet
            ['pixel' => 55, 'stop' => '940GZZLUHCL', 'line' => 'northern'], //Hendon Central
            ['pixel' => 120, 'stop' => '940GZZLUHGT', 'line' => 'northern'], //Highgate
            ['pixel' => 103, 'stop' => '940GZZLUHTD', 'line' => 'northern'], //Hampstead
            ['pixel' => 172, 'stop' => '940GZZLUKNG', 'line' => 'northern'], //Kennington
            ['pixel' => 168, 'stop' => '940GZZLUKSH', 'line' => 'northern'], //Kentish Town
            ['pixel' => 169, 'stop' => '940GZZLULSQ', 'line' => 'northern'], //Leicester Square
            ['pixel' => 169, 'stop' => '940GZZLULSQ', 'line' => 'piccadilly'], //Leicester Square
            ['pixel' => 364, 'stop' => '940GZZLUMDN', 'line' => 'northern'], //Morden
            ['pixel' => 72, 'stop' => '940GZZLUMHL', 'line' => 'northern'], //Mill Hill East
            ['pixel' => 215, 'stop' => '940GZZLUMTC', 'line' => 'northern'], //Mornington Crescent
            ['pixel' => 89, 'stop' => '940GZZLUODS', 'line' => 'northern'], //Old Street
            ['pixel' => 188, 'stop' => '940GZZLUOVL', 'line' => 'northern'], //Oval
            ['pixel' => 204, 'stop' => '940GZZLUSKW', 'line' => 'northern'], //Stockwell
            ['pixel' => 204, 'stop' => '940GZZLUSKW', 'line' => 'victoria'], //Stockwell
            ['pixel' => 348, 'stop' => '940GZZLUSWN', 'line' => 'northern'], //South Wimbledon
            ['pixel' => 24, 'stop' => '940GZZLUTAW', 'line' => 'northern'], //Totteridge & Whetstone
            ['pixel' => 300, 'stop' => '940GZZLUTBC', 'line' => 'northern'], //Tooting Bec
            ['pixel' => 316, 'stop' => '940GZZLUTBY', 'line' => 'northern'], //Tooting Broadway
            ['pixel' => 152, 'stop' => '940GZZLUTFP', 'line' => 'northern'], //Tufnell Park
            ['pixel' => 56, 'stop' => '940GZZLUWFN', 'line' => 'northern'], //West Finchley
            ['pixel' => 40, 'stop' => '940GZZLUWOP', 'line' => 'northern'], //Woodside Park
            ['pixel' => 247, 'stop' => '940GZZLUWRR', 'line' => 'northern'], //Warren Street
            ['pixel' => 247, 'stop' => '940GZZLUWRR', 'line' => 'victoria'], //Warren Street
            ['pixel' => 346, 'stop' => '940GZZNEUGST', 'line' => 'northern'], //Nine Elms
            ['pixel' => 275, 'stop' => '940GZZLUALP', 'line' => 'piccadilly'], //Alperton
            ['pixel' => 59, 'stop' => '940GZZLUASG', 'line' => 'piccadilly'], //Arnos Grove
            ['pixel' => 41, 'stop' => '940GZZLUASL', 'line' => 'piccadilly'], //Arsenal
            ['pixel' => 75, 'stop' => '940GZZLUBDS', 'line' => 'piccadilly'], //Bounds Green
            ['pixel' => 242, 'stop' => '940GZZLUBOS', 'line' => 'piccadilly'], //Boston Manor
            ['pixel' => 73, 'stop' => '940GZZLUCAR', 'line' => 'piccadilly'], //Caledonian Road
            ['pixel' => 153, 'stop' => '940GZZLUCGN', 'line' => 'piccadilly'], //Covent Garden
            ['pixel' => 11, 'stop' => '940GZZLUCKS', 'line' => 'piccadilly'], //Cockfosters
            ['pixel' => 25, 'stop' => '940GZZLUFPK', 'line' => 'piccadilly'], //Finsbury Park
            ['pixel' => 42, 'stop' => '940GZZLUFPK', 'line' => 'victoria'], //Finsbury Park
            ['pixel' => 322, 'stop' => '940GZZLUHNX', 'line' => 'piccadilly'], //Hatton Cross
            ['pixel' => 328, 'stop' => '940GZZLUHPC', 'line' => 'piccadilly'], //Hyde Park Corner
            ['pixel' => 370, 'stop' => '940GZZLUHR4', 'line' => 'piccadilly'], //Heathrow Terminal 4
            ['pixel' => 354, 'stop' => '940GZZLUHR5', 'line' => 'piccadilly'], //Heathrow Terminal 5
            ['pixel' => 338, 'stop' => '940GZZLUHRC', 'line' => 'piccadilly'], //Heathrow Terminals 2 & 3
            ['pixel' => 290, 'stop' => '940GZZLUHWC', 'line' => 'piccadilly'], //Hounslow Central
            ['pixel' => 274, 'stop' => '940GZZLUHWE', 'line' => 'piccadilly'], //Hounslow East
            ['pixel' => 306, 'stop' => '940GZZLUHWT', 'line' => 'piccadilly'], //Hounslow West
            ['pixel' => 57, 'stop' => '940GZZLUHWY', 'line' => 'piccadilly'], //Holloway Road
            ['pixel' => 344, 'stop' => '940GZZLUKNB', 'line' => 'piccadilly'], //Knightsbridge
            ['pixel' => 9, 'stop' => '940GZZLUMRH', 'line' => 'piccadilly'], //Manor House
            ['pixel' => 257, 'stop' => '940GZZLUNEN', 'line' => 'piccadilly'], //North Ealing
            ['pixel' => 226, 'stop' => '940GZZLUNFD', 'line' => 'piccadilly'], //Northfields
            ['pixel' => 27, 'stop' => '940GZZLUOAK', 'line' => 'piccadilly'], //Oakwood
            ['pixel' => 258, 'stop' => '940GZZLUOSY', 'line' => 'piccadilly'], //Osterley
            ['pixel' => 241, 'stop' => '940GZZLUPKR', 'line' => 'piccadilly'], //Park Royal
            ['pixel' => 248, 'stop' => '940GZZLURSQ', 'line' => 'piccadilly'], //Russell Square
            ['pixel' => 210, 'stop' => '940GZZLUSEA', 'line' => 'piccadilly'], //South Ealing
            ['pixel' => 43, 'stop' => '940GZZLUSGT', 'line' => 'piccadilly'], //Southgate
            ['pixel' => 227, 'stop' => '940GZZLUSHH', 'line' => 'piccadilly'], //South Harrow
            ['pixel' => 243, 'stop' => '940GZZLUSUH', 'line' => 'piccadilly'], //Sudbury Hill
            ['pixel' => 259, 'stop' => '940GZZLUSUT', 'line' => 'piccadilly'], //Sudbury Town
            ['pixel' => 107, 'stop' => '940GZZLUTPN', 'line' => 'piccadilly'], //Turnpike Lane
            ['pixel' => 91, 'stop' => '940GZZLUWOG', 'line' => 'piccadilly'], //Wood Green
            ['pixel' => 171, 'stop' => '940GZZLUBLR', 'line' => 'victoria'], //Blackhorse Road
            ['pixel' => 220, 'stop' => '940GZZLUBXN', 'line' => 'victoria'], //Brixton
            ['pixel' => 58, 'stop' => '940GZZLUHAI', 'line' => 'victoria'], //Highbury & Islington
            ['pixel' => 249, 'stop' => '940GZZLUPCO', 'line' => 'victoria'], //Pimlico
            ['pixel' => 26, 'stop' => '940GZZLUSVS', 'line' => 'victoria'], //Seven Sisters
            ['pixel' => 10, 'stop' => '940GZZLUTMH', 'line' => 'victoria'], //Tottenham Hale
            ['pixel' => 330, 'stop' => '940GZZLUVXL', 'line' => 'victoria'], //Vauxhall
            ['pixel' => 155, 'stop' => '940GZZLUWWL', 'line' => 'victoria'], //Walthamstow Central
        );

*/


