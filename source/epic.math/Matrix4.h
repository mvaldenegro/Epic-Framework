/* 
 * File:   Matrix4.h
 * Author: hunts
 *
 * Created on 3 de noviembre de 2010, 01:23 AM
 */

#ifndef MATRIX4_H
#define	MATRIX4_H

namespace Epic {
    namespace Math {
        template<typename T>
        class Matrix4<T>
        {
            public:
                Matrix4();
                Matrix4(const Matrix4<T>& other);
                ~Matrix4();
            private:
                T matrixData[16];
        };

        typedef Matrix4<float> Matrix4F;
        typedef Matrix4<double> Matrix4D;
    };
};

#endif	/* MATRIX4_H */

