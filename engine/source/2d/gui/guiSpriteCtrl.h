//-----------------------------------------------------------------------------
// Torque
// Copyright GarageGames, LLC 2011
//-----------------------------------------------------------------------------

#ifndef _GUISPRITECTRL_H_
#define _GUISPRITECTRL_H_

#ifndef _GUICONTROL_H_
#include "gui/guiControl.h"
#endif

#ifndef _IMAGE_ASSET_H_
#include "2d/assets/ImageAsset.h"
#endif

#ifndef _ANIMATION_CONTROLLER_H_
#include "2d/assets/AnimationController.h"
#endif

#ifndef _ASSET_PTR_H_
#include "assets/assetPtr.h"
#endif

#ifndef _TICKABLE_H_
#include "platform/Tickable.h"
#endif

//-----------------------------------------------------------------------------

class GuiSpriteCtrl : public GuiControl, public virtual Tickable
{
private:
    typedef GuiControl Parent;

protected:
    StringTableEntry                mImageAssetId;
    StringTableEntry                mAnimationAssetId;
    U32                             mImageFrame;
    bool                            mAnimationPaused;

    AssetPtr<ImageAsset>  mImageAsset;

    bool                            mStaticMode;
    AnimationController*            mpAnimationController;

public:
    GuiSpriteCtrl();
    virtual ~GuiSpriteCtrl();
    bool onWake();
    void onSleep();
    void onRender(Point2I offset, const RectI &updateRect);
    void renderNoImage( Point2I &offset, const RectI& updateRect );
    static void initPersistFields();

    /// Integration.
    virtual void processTick();
    virtual void interpolateTick( F32 delta ) {};
    virtual void advanceTime( F32 timeDelta ) {};

    /// Static.
    void setImage( const char* pImageMapAssetId );
    inline StringTableEntry getImage( void ) const { if ( isStaticMode() ) return mImageAssetId; else return StringTable->EmptyString; };
    void setImageFrame( const U32 imageFrame );
    inline U32 getImageFrame( void ) const { return mImageFrame; };

    /// Animation.
    void setAnimation( const char* pAnimationAssetId );
    inline StringTableEntry getAnimation( void ) const { if ( isStaticMode() ) return StringTable->EmptyString; else return mAnimationAssetId; };
    inline bool isStaticMode( void ) const { return mStaticMode; }
    void play(void);
    void pause(bool);
    void stop(void);

    // Declare type.
    DECLARE_CONOBJECT(GuiSpriteCtrl);

protected:
    static bool setImage(void* obj, const char* data) { static_cast<GuiSpriteCtrl*>(obj)->setImage( data ); return false; }
    static const char* getImage(void* obj, const char* data) { return static_cast<GuiSpriteCtrl*>(obj)->getImage(); }
    static bool writeImage( void* obj, StringTableEntry pFieldName ) { GuiSpriteCtrl* pCastObject = static_cast<GuiSpriteCtrl*>(obj); if ( !pCastObject->isStaticMode() ) return false; return pCastObject->mImageAssetId != StringTable->EmptyString; }
    static bool setImageFrame(void* obj, const char* data) { static_cast<GuiSpriteCtrl*>(obj)->setImageFrame( dAtoi(data) ); return false; }
    static bool writeImageFrame( void* obj, StringTableEntry pFieldName ) { GuiSpriteCtrl* pCastObject = static_cast<GuiSpriteCtrl*>(obj); return pCastObject->isStaticMode() && pCastObject->getImageFrame() > 0; }
    static bool setAnimation(void* obj, const char* data) { static_cast<GuiSpriteCtrl*>(obj)->setAnimation(data); return false; };
    static const char* getAnimation(void* obj, const char* data) { return static_cast<GuiSpriteCtrl*>(obj)->getAnimation(); }
    static bool writeAnimation( void* obj, StringTableEntry pFieldName ) { GuiSpriteCtrl* pCastObject = static_cast<GuiSpriteCtrl*>(obj); if ( pCastObject->isStaticMode() ) return false; return pCastObject->mAnimationAssetId != StringTable->EmptyString; }
};

#endif //_GUISPRITECTRL_H_
