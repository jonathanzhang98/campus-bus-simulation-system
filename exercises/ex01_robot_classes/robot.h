#ifndef EX01_ROBOT_CLASSES_H_
#define EX01_ROBOT_CLASSES_H_

class Robot {
  public:
    void MoveForward( int distance );
    void Display();
  private:
    float direction_angle_;
    int position_[2];
  };

#endif /* EX01_ROBOT_CLASSES_H_ */
