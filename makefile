CPP_FARM: Animal.o Farm.o Market.o farmMarket.o SheepFarm.o CowFarm.o ChickenFarm.o
	g++ Animal.o Farm.o Market.o farmMarket.o SheepFarm.o CowFarm.o ChickenFarm.o -o CPP_FARM
Animal.o: Animal.cpp Animal.h
	g++ -c Animal.cpp
Farm.o: Farm.cpp Farm.h Animal.h
	g++ -c Farm.cpp
Market.o: Market.cpp Market.h Farm.h Animal.h SheepFarm.h CowFarm.h ChickenFarm.h Exception.h 	
	g++ -c Market.cpp	
farmMarket.o: farmMarket.cpp Market.h
	g++ -c farmMarket.cpp
SheepFarm.o: SheepFarm.cpp SheepFarm.h Farm.h Animal.h Sheep.h
	g++ -c SheepFarm.cpp		
CowFarm.o: CowFarm.cpp CowFarm.h Farm.h Animal.h Cow.h
	g++ -c CowFarm.cpp
ChickenFarm.o: ChickenFarm.cpp ChickenFarm.h Farm.h Animal.h Chicken.h
	g++ -c ChickenFarm.cpp
clean:
	rm -f *.o CPP_FARM
