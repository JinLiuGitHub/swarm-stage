/*************************************************************************
 * win.h - all the X graphics stuff is here
 * RTV
 * $Id: win.h,v 1.2 2000-12-01 00:20:52 vaughan Exp $
 ************************************************************************/

#ifndef WIN_H
#define WIN_H

#include <X11/Xlib.h>

#include "world.h"

class CWorldWin
{
public:
  // constructor
  CWorldWin( CWorld* wworld, char* initFile );
  
  Window win;
  GC gc, bgc, wgc;
  
  Display* display;
  int screen;

  unsigned long red, green, blue, yellow, magenta, cyan, white, black; 
  int grey;


  int width, height, x,y;
  int iwidth, iheight, panx, pany;
  int drawMode;
   
  int showSensors;

  XEvent reportEvent;

  double xscale, yscale;
  double dimx, dimy;

  unsigned int RGB( int r, int g, int b )
    {
      return (((r << 8) | g) << 8) | b;
    };

 // data
  CWorld* world;
  CRobot* dragging;

  // methods  

  //void CheckSubscriptions( CRobot* r );
  void BoundsCheck( void );
  int LoadVars( char* initFile );
  void HandleEvent( void );
  void Update( void );
  void DragRobot( void );
  
  void PrintCoords( void );
  //void DrawSonar( CRobot* r );
  //void DrawLaser( CRobot* r );
  
  void Draw( void );
  //void DrawZones( void );
  //void DrawCrum( CCrum* aCrum );
  //void DrawCrums( void );
  void DrawRobotIfMoved( CRobot* r );
  void DrawRobot( CRobot* r );
  //void DrawRobotWithScaling( CRobot* r );
  void DrawRobotsInRect( int xx, int yy, int ww, int hh );
  void DrawRobots( void );
  void DrawWalls( void );
  void BlackBackground( void );
  void BlackBackgroundInRect(int xx, int yy, int ww, int hh  );
  void DrawWallsInRect( int xx, int yy, int ww, int hh );
  void ScanBackground( void );
  //void ScanBackgroundWithScaling( void );
  void MoveSize(void);
  void DrawInRobotColor( CRobot* r );
  unsigned long  RobotDrawColor( CRobot* r );
  void SetForeground( unsigned long color );
  void DrawLines( XPoint* pts, int numPts );
};

#endif
