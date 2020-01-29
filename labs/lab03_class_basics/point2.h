class Point2{

	private:
		float x_;
		float y_;
	public:
		Point2(); 
		Point2(float x, float y);
		float DistanceBetween(Point2 other);
		int Quadrant();
		void Print();

};
