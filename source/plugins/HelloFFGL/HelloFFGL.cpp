#include "HelloFFGL.h"

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
	- "Plugin name". This is the name as its displayed in Resolume's effect list. By putting FF_SOURCE you will create a source instead of an effect.
	- "Plugin type". Here you can let Resolume know whether the plugin is a source or effect.
	- "Plugin description" and "About" are shown in the Help panel in Resolume.
	*/
);

FFGLPlugin::FFGLPlugin()
	: CFreeFrameGLPlugin()
{
	/*This creates a parameter
	The 0 in the beginning means it's the first parameter. We'll use this later on to get the value from Resolume.
	"Does Nothing" is the name (16 character maximum
	FF_TYPE_STANDARD means it's a regular slider
	and 0.5f is it's default value */
	SetParamInfo( 0, "Does Nothing", FF_TYPE_STANDARD, 0.5f);
}

FFGLPlugin::~FFGLPlugin()
{

}

/*ProcessOpenGL is like the draw() function in processing and openframeworks.
Everything that happens in ProcessOpenGL happens everytime the plugin renders.
Even though we're not doing anything yet, 
we need to return FF_SUCCESS to let Resolume know everything is fine*/
FFResult FFGLPlugin::ProcessOpenGL(ProcessOpenGLStruct *pGL)
{
	return FF_SUCCESS;
}

/*SetFloatParameter is called by Resolume when you change a slider in the effect
Later we'll use the value to do stuff in our plugin, 
but for now we just need to let Resolume know everything is fine by returning FF_SUCCESS */
FFResult FFGLPlugin::SetFloatParameter(unsigned int index, float value)
{
	return FF_SUCCESS;
}


