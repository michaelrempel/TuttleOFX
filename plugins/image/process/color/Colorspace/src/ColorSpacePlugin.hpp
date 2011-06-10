#ifndef _TUTTLE_PLUGIN_COLORSPACE_PLUGIN_HPP_
#define _TUTTLE_PLUGIN_COLORSPACE_PLUGIN_HPP_

#include <tuttle/plugin/ImageEffectGilPlugin.hpp>
#include <tuttle/plugin/color/colorDefinitions.hpp>

#include <tuttle/plugin/color/colorSpaceAPI.hpp>

namespace tuttle {
namespace plugin {
namespace colorspace {

namespace ttlc = tuttle::plugin::color;

struct ColorSpaceProcessParams
{
	ttlc::ColorSpaceAPI		csAPI;
	
	ttlc::EParamGradationLaw	_gradationIn;
	double				_GammaValueIn;
	double				_BlackPointIn;
	double				_WhitePointIn;
	double				_GammaSensitoIn;

	ttlc::EParamGradationLaw	_gradationOut;
	double				_GammaValueOut;
	double				_BlackPointOut;
	double				_WhitePointOut;
	double				_GammaSensitoOut;
	
	ttlc::EParamLayout		_layoutIn;
	ttlc::EParamLayout		_layoutOut;
	ttlc::EParamTemp		_tempColorIn;
	ttlc::EParamTemp		_tempColorOut;
};

/**
 * @brief
 *
 */
class ColorSpacePlugin : public ImageEffectGilPlugin
{
public:
	ColorSpacePlugin( OfxImageEffectHandle handle );

	ColorSpaceProcessParams getProcessParams() const;
	void changedParam( const OFX::InstanceChangedArgs& args, const std::string& paramName );

	bool isIdentity( const OFX::RenderArguments& args, OFX::Clip*& identityClip, double& identityTime );

	void render( const OFX::RenderArguments& args );

private:
	void updateInParams();
	void updateOutParams();
	
private:
	OFX::ChoiceParam*	_paramInGradationLaw;
	OFX::ChoiceParam*	_paramOutGradationLaw;
	OFX::DoubleParam*	_paramInGamma;
	OFX::DoubleParam*	_paramOutGamma;
	OFX::DoubleParam*	_paramInBlackPoint;
	OFX::DoubleParam*	_paramOutBlackPoint;
	OFX::DoubleParam*	_paramInWhitePoint;
	OFX::DoubleParam*	_paramOutWhitePoint;
	OFX::DoubleParam*	_paramInGammaSensito;
	OFX::DoubleParam*	_paramOutGammaSensito;

	OFX::ChoiceParam*	_paramInLayout;
	OFX::ChoiceParam*	_paramOutLayout;
	OFX::ChoiceParam*	_paramInColorTemp;
	OFX::ChoiceParam*	_paramOutColorTemp;
};

}
}
}

#endif
