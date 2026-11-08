#ifndef IFACEVIEW_H
#define IFACEVIEW_H

class IFaceView
{
public:
    virtual ~IFaceView() = default;
protected:
    virtual void updateView() = 0;
};

#endif // IFACEVIEW_H
