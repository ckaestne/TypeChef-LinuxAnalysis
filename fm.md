# reading the feature model _2var file:


Variables `X` and `X_m` work as follows:

X = "y" <=> X and X_m
X = "m" <=> X and !X_m
X = "n" <=> !X

alternatively rewritten:

CONFIG_X <=> X and X_m
CONFIG_X_MODULE <=> X and !X_m
