#include "HelloFFGL.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
//  Plugin information
////////////////////////////////////////////////////////////////////////////////////////////////////

static CFFGLPluginInfo PluginInfo(
	FFGLPlugin::CreateInstance,			// Create method
	"XXX1",								// Plugin unique ID
	//this number is used the identify the plugin internally and needs to be different for each and every plugin
	"Hello FFGL!",						// Plugin name
	//the name as its displayed in the effect list
	1,						   			// API major version number
	//don't fuck with this													
	500,								// API minor version number
	//don't fuck with this
	1,									// Plugin major version number
	//if you like, you can use versioning here
	000,								// Plugin minor version number
	//if you like, you can use versioning here
	FF_EFFECT,							// Plugin type
	//this will let Resolume the plugin is an effect or source
	"Completely empty example",			// Plugin description
	//this info can be seen in the Help box
	"Joris de Jong // Resolume"			// About 
	//this info can be seen in the Help box
);

FFGLPlugin::FFGLPlugin()
	: CFreeFrameGLPlugin()
{

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

