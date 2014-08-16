KARATE_CHOP_DIR = karate_chop
DATA_MUNGING_DIR = data_munging
PP_COL1_DIR = pp_col1
STACK_QUEUE_DIR = stack_queue
DIGIT_COUNTER_DIR = digit_counter

.PHONY: karate_chop_kata data_munging clean

all: karate_chop_kata pp_col1_kata stack_queue_kata digit_counter_kata

karate_chop_kata:
	$(MAKE) -C $(KARATE_CHOP_DIR)

data_munging_kata:
	$(MAKE) -C $(DATA_MUNGING_DIR)

pp_col1_kata:
	$(MAKE) -C $(PP_COL1_DIR)

stack_queue_kata:
	$(MAKE) -C $(STACK_QUEUE_DIR)

digit_counter_kata:
	$(MAKE) -C $(DIGIT_COUNTER_DIR)

clean:
	$(MAKE) -C $(KARATE_CHOP_DIR) clean
	$(MAKE) -C $(DATA_MUNGING_DIR) clean
	$(MAKE) -C $(PP_COL1_DIR) clean
	$(MAKE) -C $(STACK_QUEUE_DIR) clean
	$(MAKE) -C $(DIGIT_COUNTER_DIR) clean
	rm -rf ./bin/*
