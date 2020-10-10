
class Game {
  public:
    void printGrid();
    int genNumber();
    virtual void iterate() = 0;
    void copyGrid();

}
