KARATE_CHOP_DIR = karate_chop
DATA_MUNGING_DIR = data_munging

.PHONY: karate_chop_kata data_munging clean

all: karate_chop_kata

karate_chop_kata:
	$(MAKE) -C $(KARATE_CHOP_DIR)

data_munging_kata:
	$(MAKE) -C $(DATA_MUNGING_DIR)

clean:
	$(MAKE) -C $(KARATE_CHOP_DIR) clean
	$(MAKE) -C $(DATA_MUNGING_DIR) clean
	rm -rf ./bin/*
