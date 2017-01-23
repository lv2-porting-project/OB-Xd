#pragma once
/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Gui/Knob.h"
#include "Gui/TooglableButton.h"
#include "Gui/ButtonList.h"


//==============================================================================
/**
*/
class ObxdAudioProcessorEditor :
	public AudioProcessorEditor,
	// public AudioProcessorListener,
	public ChangeListener,
	public Slider::Listener,
	public Button::Listener,
	public ComboBox::Listener
{
public:
    ObxdAudioProcessorEditor(ObxdAudioProcessor* ownerFilter);
    ~ObxdAudioProcessorEditor();

	void mouseUp(const MouseEvent& e);
	void paint(Graphics& g);

	//==============================================================================
	void changeListenerCallback (ChangeBroadcaster* source);

private:
	Knob* addNormalKnob(int x , int y ,ObxdAudioProcessor* filter, int parameter,String name,float defval);
	Knob* addTinyKnob(int x , int y ,ObxdAudioProcessor* filter, int parameter,String name,float defval);
	void placeLabel(int x , int y,String text);
	TooglableButton* addNormalTooglableButton(int x , int y , ObxdAudioProcessor* filter,int parameter,String name);
	TooglableButton* addTinyTooglableButton(int x , int y , ObxdAudioProcessor* filter,int parameter,String name);

	ButtonList* addNormalButtonList(int x , int y ,int width, ObxdAudioProcessor* filter,int parameter,String name,Image img);
    void sliderValueChanged (Slider*);
	void buttonClicked (Button *);
    void comboBoxChanged(ComboBox*);

    Knob* addNormalKnobClassic(int x , int y ,ObxdAudioProcessor* filter, int parameter,String name,float defval);
    Knob* addTinyKnobClassic(int x , int y ,ObxdAudioProcessor* filter, int parameter,String name,float defval);
    TooglableButton* addNormalTooglableButtonClassic(int x , int y , ObxdAudioProcessor* filter,int parameter,String name);
	ButtonList* addNormalButtonListClassic(int x , int y ,int width, ObxdAudioProcessor* filter,int parameter,String name,Image img);

	void rebuildComponents();

	//==============================================================================
	ObxdAudioProcessor* getFilter() noexcept    { return (ObxdAudioProcessor*)getAudioProcessor();}

	//==============================================================================
	Knob* cutoffKnob,*resonanceKnob,*osc1PitchKnob,*osc2PitchKnob,*osc2DetuneKnob,*volumeKnob,
		*portamentoKnob,*voiceDetuneKnob,*filterEnvelopeAmtKnob,*pulseWidthKnob,*xmodKnob,*multimodeKnob,*attackKnob,*decayKnob,*sustainKnob,*releaseKnob,
		*fattackKnob,*fdecayKnob,*fsustainKnob,*freleaseKnob,*osc1MixKnob,*osc2MixKnob,*noiseMixKnob,
		*filterDetuneKnob,*envelopeDetuneKnob,*portamentoDetuneKnob,
		*tuneKnob,
		*lfoFrequencyKnob,*lfoAmt1Knob,*lfoAmt2Knob,
		*pan1Knob,*pan2Knob,*pan3Knob,*pan4Knob,*pan5Knob,*pan6Knob,*pan7Knob,*pan8Knob,
		*brightnessKnob,*envPitchModKnob,
		*bendLfoRateKnob,*veloAmpEnvKnob,*veloFltEnvKnob,*transposeKnob;

	TooglableButton* hardSyncButton,*osc1SawButton,*osc2SawButton,*osc1PulButton,*osc2PulButton,*filterKeyFollowButton,*unisonButton,*pitchQuantButton,
		*filterHQButton,*filterBPBlendButton,
		*lfoSinButton,*lfoSquareButton,*lfoSHButton,*lfoOsc1Button,*lfoOsc2Button,*lfoFilterButton,
		*lfoPwm1Button,*lfoPwm2Button,
		*bendRangeButton,*bendOsc2OnlyButton,
		*fourPoleButton,*asPlayedAllocButton,*midiLearnButton,*midiUnlearnButton;

	ButtonList *voiceSwitch,*legatoSwitch;

	File skinFolder;
};

#endif  // PLUGINEDITOR_H_INCLUDED