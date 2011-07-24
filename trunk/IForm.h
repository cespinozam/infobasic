#ifndef IFORM_H
#define IFORM_H

class IForm
{
public:
    // Set window text.
    virtual void putTexts() = 0;
    // Initialize widgets and connect signals.
    virtual void setuid() = 0;
};

#endif // IFORM_H
