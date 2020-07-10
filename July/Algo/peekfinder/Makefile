VERSION_1DPEAK := peak1D
VERSION_2DPEAK := peak2D

VERSION_1DPEAK_OBJ := PeakFinder1DVersion.o
VERSION_2DPEAK_OBJ := PeakFinder2DVersion.o

all: $(VERSION_1DPEAK) $(VERSION_2DPEAK)
	@echo "Peak 1-D version"
	./$(VERSION_1DPEAK)
	@echo
	@echo "=================================================="
	@echo
	@echo "Peak 2-D version"
	./$(VERSION_2DPEAK)

$(VERSION_1DPEAK): $(VERSION_1DPEAK_OBJ)
	$(CC) -o $@ $(VERSION_1DPEAK_OBJ)

$(VERSION_2DPEAK): $(VERSION_2DPEAK_OBJ)
	$(CC) -o $@ $(VERSION_2DPEAK_OBJ)

clean:
	rm -rf *.o ~* $(PEAK)
