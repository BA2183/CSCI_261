#ifndef FACE_HPP
#define FACE_HPP
/**
 * @brief an object to hold index number of vertices to form a face made of 3 vertices
 * 
 */
struct Face {
    /**
     * @brief first vertex point of the face
     * 
     */
    int p;

    /**
     * @brief second vertex point of the face
     * 
     */
    int q;

    /**
     * @brief third vertex point of the face
     * 
     */
    int r;
};
#endif