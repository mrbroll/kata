KARATE_CHOP_DIR = karate_chop

.PHONY: karate_chop_kata clean

all: karate_chop_kata

karate_chop_kata:
	$(MAKE) -C $(KARATE_CHOP_DIR)

clean:
	$(MAKE) -C $(KARATE_CHOP_DIR) clean
	rm -rf ./bin/*
