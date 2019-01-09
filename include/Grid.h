#ifndef __GRID_H
#define __GRID_H


#include <map>

#include "Point.h"
#include "Slot.h"
#include "Shape.h"

/**
 * @brief This class is a container for all the objects of the scene, the triangles of the objects are stored on the slot depending on
 * whether they intersect each slot or not, the grid is divided into slot, each slot is a step_x*step_y*step_z cube.
*/
class Grid
{
public:
    /**
     * @brief Grid A grid that contains all of the triangles of the scene to render
     * @param min_grid The minimum in each direction of the grid
     * @param max_grid The maximum in each direction of the grid
     * @param step_x The size in the x direction of each slot of the grid
     * @param step_y The size in the y direction of each slot of the grid
     * @param step_z The size in the z direction of each slot of the grid
     */
    Grid(Point min_grid, Point max_grid, int step_x, int step_y, int step_z);

    /**
     * @brief add_triangles Adds all of the triangles in the list to the slots that they intersect, using the add_triangle helper function
     * @param triangles
     */
    void add_shapes(vector<Shape*> shapes);

    /**
     * @brief add_triangle Adds a triangle to the slots that it intersects
     * @param t
     */
    void add_shape(Shape* s);

    /**
     * @brief get_name name getter
     * @return The name of the grid
     */
    string get_name();

    /**
     * @brief get_step_x
     * @return
     */
    float get_step_x() const;


    /**
     * @brief get_step_y
     * @return
     */
    float get_step_y() const;

    /**
     * @brief get_step_z
     * @return
     */
    float get_step_z() const;

    /**
     * @brief set_name name setter
     * @param name
     */
    void set_name(string name);

    /**
     * @brief set_step_x step_x setter
     * @param step_x
     */
    void set_step_x(float step_x);

    /**
     * @brief set_step_y step_y setter
     * @param step_y
     */
    void set_step_y(float step_y);

    /**
     * @brief set_step_z step_z setter
     * @param step_z
     */
    void set_step_z(float step_z);

    /**
     * @brief get_min_grid Returns the minimum of the grid in each direction
     * @return A point representing the minimum in each direction
     */
    Point get_min_grid() const;

    /**
     * @brief get_max_grid Returns the maximum of the grid in each direction
     * @return A point representing the maximum in each direction
     */
    Point get_max_grid() const;

    /**
     * @brief set_min_grid Sets the minimum of the grid in each direction
     * @param min_grid The new value of the min in each direction
     */
    void set_min_grid(const Point &min_grid);

    /**
     * @brief set_max_grid Sets the maximum of the grid in each direction
     * @param max_grid The new value of the max in each direction
     */
    void set_max_grid(const Point &max_grid);

    /**
     * @brief get_slot Return a pointer to the slot which has min_slot as min_slot
     * @param min_slot The point to look for as min_slot
     * @return A pointer to the corresponding slot
     */
    Slot* get_slot(Point min_slot);

    /**
     * @brief get_slots Getter of all the grid slots
     * @return
     */
    std::vector<std::vector<std::vector<Slot*>>> get_slots();

    HitRecord intersect(Ray r) const;

    Grid(std::vector<Shape*> shapes,int max_index_x, int max_index_y, int max_index_z);

    int get_max_index_x();
    void set_max_index_x(int max_index_x);

    void set_max_index_y(int max_index_y);
    int get_max_index_y();

    int get_max_index_z();
    void set_max_index_z(int max_index_z);

private:

    /**
     * @brief _slots The list of slots of the grid
     */
    std::vector<std::vector<std::vector<Slot*>>> _slots;

    /**
     * @brief _min_grid, _max_grid The minimum of the grid in each direction
     */
    Point _min_grid, _max_grid;
    /**
     * @brief _step_x, _step_y, _step_z The step in each direction of the grid
     */
    float _step_x, _step_y, _step_z;

    int _max_index_x, _max_index_y, _max_index_z;
};

#endif // GRID_H
