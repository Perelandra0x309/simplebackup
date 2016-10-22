#ifndef _BARBERPOLE_H_
#define _BARBERPOLE_H_

#include <View.h>

enum TBarberPoleDirection {
	bpdLeftToRight = 0
,   bpdRightToLeft
};

class BarberPole : public BView {
public:
	BarberPole(BRect pRect, const char *pName, uint32 resizingMode, uint32 flags, TBarberPoleDirection pDirection = bpdLeftToRight);
	~BarberPole();
	
	void	Start();
	void	Stop();
	bool	IsRunning();
	
	// Property functions
	virtual void	SetActive(bool bActive);
	virtual bool	Active(void) const { return is_running; }

	virtual void	SetDirection(TBarberPoleDirection d) { direction = d; }
	virtual TBarberPoleDirection Direction() const { return direction; }

protected:
	thread_id	spinning_thread_id;
	bool		is_running;
	
private:
	TBarberPoleDirection direction;
	static 	int32 	spinningThread(void *data);
};

#endif