#ifndef SEGMENT_H
#define SEGMENT_H	

class Segment {
	private:
		int m_x;
		int m_y;
	public:
		Segment(int x, int y) : m_x(x), m_y(y) {}
		inline int getX() { return m_x; }
		inline void setX(int x) { m_x = x; }
		inline int getY() { return m_y; }
		inline void setY(int y) { m_y = y; }
};

#endif