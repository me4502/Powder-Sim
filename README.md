# The Powder Toy - October 2011

##### Get latest version here:  [Website Pending]


To use online features such as saving, you need to register at: [website pending]


## Thanks:

---------------------------------------------------------------------------

### [Original]
Stanislaw K Skowronek<br />

### [TPT]
Simon Robertshaw<br />
Skresanov Savely<br />
cracker64<br />
Catelite<br />
Matthew Miller<br />
Randalserrano<br />
vanquish349<br />
Bryan Hoyle<br />
Nathan Cousins<br />
jacksonmj<br />
Lieuwe Mosch<br />
Anthony Boot<br />
Matthew Miller<br />


### [Powder Sim]
Matthew Miller<br />
EyesIsMine<br />
PizzaPlatypus<br />
vanquish349<br />
randalserrano<br />
Anthony Boot<br />
Matthew Miller<br />

### [Contributers]
Antonvrg


## Instructions:

---------------------------------------------------------------------------

Click on the elements with the mouse and draw in the field, like in MS Paint. The rest of the game is learning what happens next.



## Controls:

---------------------------------------------------------------------------

**Caps Lock**  Specific Element Erase<br />
**Insert**     Replace mode<br />
**TAB**        Circle/Square Brush<br />
**Space**      Pause<br />
**Q** 		     Quit<br />
**Esc** 	     Quit<br />
**Z** 		     Zoom<br />
**S** 		     Save stamp (+ Ctrl when STK2 is out)<br />
**L** 		     Load last saved stamp<br />
**K** 		     Stamp library<br />
**C** 		     Cycle view mode<br />
**1-9** 	     Set view mode<br />
**P** 		     Save screenshot to .ppm<br />
**F** 		     Pause and go to next frame<br />
**G** 		     Grid<br />
**H** 		     Show/Hide HUD<br />
**D** 		     Debug mode (+ Shift when STK2 is out)<br />
**I** 		     Invert Pressure and Velocity map<br />
**T** 	       Vine mode<br />
**W** 	     	 Toggle gravity modes (+ Ctrl when STK2 is out)<br />
**R** 	     	 Reset LIFE generation (when in Debug mode)<br />
**N**	     	   "Sand effect" for drawing powders<br />
**~** 		     Console<br />
**=** 		     Reset pressure and velocity map<br />
**[** 		     Decrase brush size<br />
**]** 		     Increase brush size<br />

**Ctrl + C/V/X** 		       Copy/Paste/Cut<br />
**Ctrl + Z** 		           Undo<br />
**Ctrl + Cursor drag** 	   Rectangle<br />
**Shift + Cursor drag** 	 Line<br />
**MMB / Alt + LMB click**  Sample element<br />
**Mouse scroll** 		       Change brush size<br />
**Ctrl + Mouse scroll** 	 Change vertical brush size<br />
**Shift + Mouse scroll** 	 Change horizontal brush size<br />
**Shift + Ctrl + R** 	     Horizontal mirror for selected area<br />
**Ctrl + R** 		           Rotate selected area counterclockwise<br />
**Ctrl + Left**            Alt	Select subject for Specific Element erase<br />
**Ctrl + =** 		           Reset Electricity<br />


## Command Line:

---------------------------------------------------------------------------

**scale:1** - Normal window resolution<br />
**scale:2** - Doubled window resolution<br />
**kiosk**   - Fullscreen mode<br />
**proxy:server:port** - (eg. proxy:wwwcache.lancs.ac.uk:8080)<br />
**open <file>** - Opens the file as a stamp or game save<br />
**ddir <directory>** - Directory used for saving stamps and preferences<br />

## History:

---------------------------------------------------------------------------
### [Our Additions]

<pre>
* Version 1.0
      o Makefile updated for RHEL
      o Francium Added
</pre>

### [Simons Additions]

<pre>
*  Version 65.4
      o "Sand" effect for drawing powders, activate with "N"
      o Elements from Maksprog's mod
              o LIGH - Lightning
              o DEST - Variation of BOMB
              o TESC - Tesla coil, creates lightning
              o EMP - Destroys electronic components
      o Fix bug with infinite temperature
      o Fix beta enrolling
      o Add a new mode to filter, subtract (tmp of 3)
*  Version 47.3
      o Enhanced visual effects for Portals
      o Glow now has more stimuli (Green: Pressure, Blue: Movement, Red: Heat)
      o Python console (Unavailable in current beta)
      o Fixed issue where you appear to be logged in but aren't.
      o Changes to Quartz (Grows like crystal when exposed to salt water)
      o Singularity explodes upon death
      o Save ID shown after saving and on Open Dialog
      o Rearrangement of some elements (Photons in Radioactive, Thunder in Explosive, etc)
*  Version 46.3
      o Major game engine and performance improvements.
      o New GOL elements.
      o More secure login system
* Version 45.2
      o Important! Fix for Auto-update in Linux.
* Version 45.1
      o Small bugfix for Lava and Portals.
      o Fix crash when 2 of the same stickman are somehow placed.
* Version 45.0
      o Fix bug where description would persist after a reset
      o ARAY now passes through INWR without interracting.
      o INST has been fixed and placed in the Electronics menu
      o Photons turn into neutrons when passing through INVS
      o Other small bug fixes.
* Version 44.7
      o Fix login and dialoq text box issues.
      o Small bugfixes to some elements.
      o Additional 'debug' information.
      o Increase WIFI channels
      o Add missing icons for menus and display modes.
* Version 44.6
      o Fix for brush issues when using small brushes.
      o Pause state saving modifications.
* Version 44.5
      o Fix corruption issues with FAN wall.
* Version 44.4
      o Many new elements from cracker64s mod.
      o Pause state is saved.
      o Particle properties are saved more accurately.
      o Improved search and save viewing, added descriptions and comments.
* Version 42.3
      o Changed internal temperature scale to kelvin.
      o Fixed physics bug with certain powders.
      o Fixed bug when loading saves with stickman in.
      o Added save history, the ability to view previous versions of saves.
* Version 42.0
      o New Elements: Brick, Glow, Diesel, many others.
      o Source code seperation
      o Lots of other stuff that I can't remember.
* Version 41.3
      o Fixes bug where Insulation would burst into flames randomly
      o Moves fancy new effects into a separate colour mode.
* Version 39.0
      o New element: Liquid Crystal
      o New element: Battery
      o New element: Noble Gas
      o Copy, cut and paste
* Version 38.0
      o New element: Nitrogen Ice
      o New element: Electrode (Allows currents to jump)
      o Adds a lock icon to private saves.
      o Binds the '[' and ']' keys to decrease/increase the cursor size for those without scroll wheels.
      o Fixes wall menu issue where walls would be selected by accident.
* Version 37.0
      o New element: Plasma
      o New element: Thunder/Lighting
      o New wall: Allows only gas
      o Fixes HUD bug.
* Version 36.3
      o Introduced public & private saving (more info here)
* Version 36.2
      o Fixes bug where rating would appear as Zero in search.
* Version 36.1
      o Feature: Particle sampling with middle click
      o Feature: Download from website, for information, see the "Announcement" forum section.
* Version 36.0
      o Changes to the menu
      o New elements for electronics
      o New voting system
      o Added functions for moderating
* Version 35.0
      o Added elements: White Hole, Black Hole, Rubidium and Liquid Rubidium
      o Fixed the OSX version
      o Some other bug fixes that I forgot.
* Version 34.0
      o Fixed certain graphical glitches
      o Changed menu categories
      o Increased menu hover size
* Version 33.2
      o Photons can now ignite flammable materials.
      o Distilled water will turn into water on contact with water.
      o Fixes burning broken metal
* Version 34.0 (Beta 6)
      o New element menu layout
      o New element: Liquid Nitrogen
* Version 34.0 (Beta 5)
      o Improvements to stamp browser
      o Added Glyphs for Blob and Heat view
      o Fixed bug that caused a crash on Windows systems when using the wall tool in the window edges.(Fixed more than last time)
      o Decreased/Increased Min/Max Temperatures.
* Version 34.0 (Beta 4)
      o Cool, heat and Air no longer crash upon flood fill
      o Fixed bug that caused a crash on Windows systems when using the wall tool in the window edges.
      o Stamp browser now allows multiple pages.
      o Improved the zoom features, allowing inspection.
      o Modification to temperature simulation, pressure is now taken into account with transitions from liquid to gas and vice-versa
      o Fixed bug where Salt-water would not leave salt upon evaporation
* Version 34.0 (Beta 3)
      o Bug fixes for uranium
      o Fixed bug where extremely hot objects would show as black
      o Fixed but where stamps would not be loaded
* Version 34.0 (Beta 2)
      o Bug fixes
      o Legacy Mode state is now saved and loaded
      o Fix "Cool" and "Heat" when drawing on walls.
      o Air now works.
* Version 34.0 (Beta 1)
      o Bug fixes
      o Legacy Mode (Older saves will load with legacy mode, preserving the functionality of the older powder toy)
      o Heat and Cool elements. (Air is broken until next beta.)
* Version 34.0 (Beta)
      o Heat Simulation (With free bugs and glitches)
      o New Element: Uranium, heats up when pressurised.
      o New button, AIR, provides instant air, the Alt+Click and Middle Click can be used as a shortcut
* Version 33.1
      o Masses of bug fixes
      o Broken metal and breakable metal fixed (conduction)
      o Liquid collisions fixed.
* Version 33.0
      o Added Photons, particles similar to neutrons that travel in straight lines
      o Added destructable metal
      o Fixed a glitch with diamond that would make it appear invisible to air pressure.
* Version 32.0
      o Added Diamond (Thanks to ief014)
      o Fixed packaging errors for the Windows release
* Version 31.0
      o Plutonium more powerful
      o Changes to the handling of lava (Now solidifies into the same material it was melted from).
      o New element: Salt.
      o New element: Salt water
* Version 30.0
      o Added the ability to change the zoom strength
      o Increased the maximum pen size.
      o New element: Concrete, tougher than stone, stackable.
      o New element: Distilled water, similar to water, but doesn't conduct electricity
      o Changed menu layout, walls at the bottom, elements at the top (to allow for more future elements)
      o 32bit colour for Macintosh versions.
* Version 28.4
      o Fixes crash when loading a save with acid.
      o Another tiny change for acid colour in blob mode
* Version 28.3
      o Fixes acid colour in blob mode
      o Fixes blob mode colour on Macintosh and 16bit colour systems
* Version 28.2
      o Quit confirmation dialogue when using the escape key
      o Walls are "blobbed" in Blob view
* Version 28.1
      o Steam rises
      o Acid drastically changed, now dilutes itself when dissolving other particles
* Version 28.0
      o "Yellow wall" bug fix, doesn't absorb particles when placed above another wall type.
      o New wall type added: E-Hole, absorbs particles when unpowered, released them when powered.
</pre>
