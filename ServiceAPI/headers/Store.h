#ifndef __Store_H_
#define __Store_H_

class Store {
	private:
		int idStore;
		double storex;
		double storey;
		/* necesar pentru Task 1, cerinta 2 */
		int discountgiven;

	public:

		/* Constructor default */
		Store( );

		/* Constructor */
		Store( int idStore, double storex, double storey, int discountgiven );

		/* Destructor */
		~Store( );

		/* Copy assignment */
		Store( const Store& obiectulStore );

		/* Suprascrierea operatorului de atribuire */
		void operator=( const Store& obiectulStore );

		/* Extragere idstore */
		int getIdStore( );

		/* Extragere StoreX */
		double getStoreX( );

		/* Extragere StoreY */
		double getStoreY( );

		/* Extragere Discount Dat */
		int getDiscountGiven( );

		/* Setare Discount Dat */
		void setDiscountGiven( int discount );

};

#endif // __Store_H_