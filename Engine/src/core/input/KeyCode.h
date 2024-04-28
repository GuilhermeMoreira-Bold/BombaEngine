#pragma once

namespace KongInput{
	struct KeyCode {
		enum Keys {
			#define KONG_KEY_SPACE              32
			#define KONG_KEY_APOSTROPHE         39  /* ' */
			#define KONG_KEY_COMMA              44  /* , */
			#define KONG_KEY_MINUS              45  /* - */
			#define KONG_KEY_PERIOD             46  /* . */
			#define KONG_KEY_SLASH              47  /* / */
			#define KONG_KEY_0                  48
			#define KONG_KEY_1                  49
			#define KONG_KEY_2                  50
			#define KONG_KEY_3                  51
			#define KONG_KEY_4                  52
			#define KONG_KEY_5                  53
			#define KONG_KEY_6                  54
			#define KONG_KEY_7                  55
			#define KONG_KEY_8                  56
			#define KONG_KEY_9                  57
			#define KONG_KEY_SEMICOLON          59  /* ; */
			#define KONG_KEY_EQUAL              61  /* = */
			#define KONG_KEY_A                  65
			#define KONG_KEY_B                  66
			#define KONG_KEY_C                  67
			#define KONG_KEY_D                  68
			#define KONG_KEY_E                  69
			#define KONG_KEY_F                  70
			#define KONG_KEY_G                  71
			#define KONG_KEY_H                  72
			#define KONG_KEY_I                  73
			#define KONG_KEY_J                  74
			#define KONG_KEY_K                  75
			#define KONG_KEY_L                  76
			#define KONG_KEY_M                  77
			#define KONG_KEY_N                  78
			#define KONG_KEY_O                  79
			#define KONG_KEY_P                  80
			#define KONG_KEY_Q                  81
			#define KONG_KEY_R                  82
			#define KONG_KEY_S                  83
			#define KONG_KEY_T                  84
			#define KONG_KEY_U                  85
			#define KONG_KEY_V                  86
			#define KONG_KEY_W                  87
			#define KONG_KEY_X                  88
			#define KONG_KEY_Y                  89
			#define KONG_KEY_Z                  90
			#define KONG_KEY_LEFT_BRACKET       91  /* [ */
			#define KONG_KEY_BACKSLASH          92  /* \ */
			#define KONG_KEY_RIGHT_BRACKET      93  /* ] */
			#define KONG_KEY_GRAVE_ACCENT       96  /* ` */
			#define KONG_KEY_WORLD_1            161 /* non-US #1 */
			#define KONG_KEY_WORLD_2            162 /* non-US #2 */

					/* Function keys */
			#define KONG_KEY_ESCAPE             256
			#define KONG_KEY_ENTER              257
			#define KONG_KEY_TAB                258
			#define KONG_KEY_BACKSPACE          259
			#define KONG_KEY_INSERT             260
			#define KONG_KEY_DELETE             261
			#define KONG_KEY_RIGHT              262
			#define KONG_KEY_LEFT               263
			#define KONG_KEY_DOWN               264
			#define KONG_KEY_UP                 265
			#define KONG_KEY_PAGE_UP            266
			#define KONG_KEY_PAGE_DOWN          267
			#define KONG_KEY_HOME               268
			#define KONG_KEY_END                269
			#define KONG_KEY_CAPS_LOCK          280
			#define KONG_KEY_SCROLL_LOCK        281
			#define KONG_KEY_NUM_LOCK           282
			#define KONG_KEY_PRINT_SCREEN       283
			#define KONG_KEY_PAUSE              284
			#define KONG_KEY_F1                 290
			#define KONG_KEY_F2                 291
			#define KONG_KEY_F3                 292
			#define KONG_KEY_F4                 293
			#define KONG_KEY_F5                 294
			#define KONG_KEY_F6                 295
			#define KONG_KEY_F7                 296
			#define KONG_KEY_F8                 297
			#define KONG_KEY_F9                 298
			#define KONG_KEY_F10                299
			#define KONG_KEY_F11                300
			#define KONG_KEY_F12                301
			#define KONG_KEY_F13                302
			#define KONG_KEY_F14                303
			#define KONG_KEY_F15                304
			#define KONG_KEY_F16                305
			#define KONG_KEY_F17                306
			#define KONG_KEY_F18                307
			#define KONG_KEY_F19                308
			#define KONG_KEY_F20                309
			#define KONG_KEY_F21                310
			#define KONG_KEY_F22                311
			#define KONG_KEY_F23                312
			#define KONG_KEY_F24                313
			#define KONG_KEY_F25                314
			#define KONG_KEY_KP_0               320
			#define KONG_KEY_KP_1               321
			#define KONG_KEY_KP_2               322
			#define KONG_KEY_KP_3               323
			#define KONG_KEY_KP_4               324
			#define KONG_KEY_KP_5               325
			#define KONG_KEY_KP_6               326
			#define KONG_KEY_KP_7               327
			#define KONG_KEY_KP_8               328
			#define KONG_KEY_KP_9               329
			#define KONG_KEY_KP_DECIMAL         330
			#define KONG_KEY_KP_DIVIDE          331
			#define KONG_KEY_KP_MULTIPLY        332
			#define KONG_KEY_KP_SUBTRACT        333
			#define KONG_KEY_KP_ADD             334
			#define KONG_KEY_KP_ENTER           335
			#define KONG_KEY_KP_EQUAL           336
			#define KONG_KEY_LEFT_SHIFT         340
			#define KONG_KEY_LEFT_CONTROL       341
			#define KONG_KEY_LEFT_ALT           342
			#define KONG_KEY_LEFT_SUPER         343
			#define KONG_KEY_RIGHT_SHIFT        344
			#define KONG_KEY_RIGHT_CONTROL      345
			#define KONG_KEY_RIGHT_ALT          346
			#define KONG_KEY_RIGHT_SUPER        347
			#define KONG_KEY_MENU               348
	};

	enum Buttons {
		#define KONG_MOUSE_BUTTON_1         0
		#define KONG_MOUSE_BUTTON_2         1
		#define KONG_MOUSE_BUTTON_3         2
		#define KONG_MOUSE_BUTTON_4         3
		#define KONG_MOUSE_BUTTON_5         4
		#define KONG_MOUSE_BUTTON_6         5
		#define KONG_MOUSE_BUTTON_7         6
		#define KONG_MOUSE_BUTTON_8         7
		#define KONG_MOUSE_BUTTON_LAST      KONG_MOUSE_BUTTON_8
		#define KONG_MOUSE_BUTTON_LEFT      KONG_MOUSE_BUTTON_1
		#define KONG_MOUSE_BUTTON_RIGHT     KONG_MOUSE_BUTTON_2
		#define KONG_MOUSE_BUTTON_MIDDLE    KONG_MOUSE_BUTTON_3
	};
	};
}