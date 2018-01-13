#include "HelloFFGL.h"

//here we define the word 'theFirstParam' to equal zero
//this is handy so we don't have to remember which index each param has
#define theFirstParam 0

////////////////////////////////////////////////////////////////////////////////////////////////////
//  Plugin information
////////////////////////////////////////////////////////////////////////////////////////////////////

static CFFGLPluginInfo PluginInfo(
	FFGLPlugin::CreateInstance,			// Create method
	"XXX1",								// Plugin unique ID
	"Hello FFGL!",						// Plugin name
	1,						   			// API major version number												
	500,								// API minor version number
	1,									// Plugin major version number
	000,								// Plugin minor version number
	FF_EFFECT,							// Plugin type
	"Completely empty example",			// Plugin description
	"Joris de Jong // Resolume"			// About 

	/*The important bits here are:
	- "Plugin unique ID". This number is used the identify the plugin internally and needs to be different for each and every FFGL plugin in existence.
	Is there a single list where you can see all the IDs that are already in use? No. Feel free to organise one. 
	My plugins start with HV and then have two numbers identifying them. So HV01 is my first plugin. Resolume's plugins start with Axxx
	- "Plugin name". This is the name as its displayed in Resolume's effect list. 
	- "Plugin type". Here you can let Resolume know whether the plugin is a source or effect. By putting FF_SOURCE you will create a source instead of an effect.
	- "Plugin description" and "About" are shown in the Help panel in Resolume.
	*/
);

FFGLPlugin::FFGLPlugin()
	: CFreeFrameGLPlugin()
{
	/*This creates a parameter
	Instead of using 0 in the beginning, we use our define 'theFirstParam'
	"Does Nothing" is the name (16 character maximum)
	FF_TYPE_STANDARD means it's a regular slider
	and 0.5f is it's default value */
	SetParamInfo( theFirstParam, "Does Nothing", FF_TYPE_STANDARD, 0.5f);

	//because we set our param to be 0.5f by default, it makes sense that our float variable also starts off at 0.5f
	aFloat = 0.5f;

	/*This will make sure that the plugin gets recognised as an EFFECT on both OSX and Windows.
	A SOURCE has 0 inputs
	An EFFECT has 1 input
	A TRANSITION has 2 inputs
	So why is the definition there in the CreateInstance call. I don't know. Someone must have thought that was a good idea at the time */
	SetMinInputs( 1 );
	SetMaxInputs( 1 );
}

FFGLPlugin::~FFGLPlugin()
{

}

/*ProcessOpenGL is like the draw() function in processing and openframeworks.
Everything that happens in ProcessOpenGL happens everytime the plugin renders.*/
FFResult FFGLPlugin::ProcessOpenGL(ProcessOpenGLStruct *pGL)
{
	//clear the background to a nice neutral grey
	glClearColor( 0.23f, 0.23f, 0.23f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );

	//set the color to Arena cyan
	glColor4f( 0.5f, 1.0f, 0.82f, 1.0f );
	
	//now, we create a variable to hold the coordinates of the four corners of our rectangle
	GLfloat verts[] =
	{
		-0.5f, 0.5f, //top left
		0.5f, 0.5f, //top right
		0.5f, -0.5f, //bottom right
		-0.5f, -0.5f //bottom left
	};

	//and we draw those corners as a triangle fan
	glEnableClientState( GL_VERTEX_ARRAY );
	glVertexPointer( 2, GL_FLOAT, 0, verts );
	glDrawArrays( GL_TRIANGLE_FAN, 0, 4 );

	return FF_SUCCESS;
}

/* SetFloatParameter is called by Resolume when you change a slider in the effect */
FFResult FFGLPlugin::SetFloatParameter(unsigned int index, float value)
{
	//now we use the callback to set our internal float variable, whenever the slider in Resolume is changed
	switch (index)
	{
	case theFirstParam:
		aFloat = value; //this means we're setting our float to whatever value the first parameter has in Resolume
		break;
	}

	return FF_SUCCESS;
}

/* GetFloatParameter is used by Resolume to display the value on the right side of the parameter
   For instance if you're controlling rotation of something, you can use a multiplier here to show the value in degrees */
float FFGLPlugin::GetFloatParameter( unsigned int index )
{
	switch ( index )
	{
	case theFirstParam:
		return aFloat; //right now, we just want to return the value of our float
		break;
	default:
		return 0.0f; //to be safe, always return something
		break;
	}

	
}


