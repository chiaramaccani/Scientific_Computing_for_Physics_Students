
import pytest
import numpy as np
from daxpy import daxpy


@pytest.mark.parametrize(
    "dim,a", 
    [
        (10, 3.0),
        (int(1e6), -1.5),
        (int(1e8), 0.0)
    ], 
    ids=["small_a3", "medium_a-1.5", "large_a0"]
)
def test_daxpy(dim, a):

    a = 3.0
    x_value = 0.1
    y_value = 7.1
    d_expected = a*x_value+y_value

    x = np.full(int(dim), x_value)
    y = np.full(int(dim), y_value)
    d = daxpy(x,y,a)
    
    assert d.shape == (int(dim),), f"Expected shape {(int(dim),)}, but got {d.shape}"
    assert d.dtype == np.float64, f"Expected dtype {np.float64}, but got {d.dtype}"
    assert np.allclose(d, np.full(int(dim), d_expected)), f"Expected {d_expected}, but got {d}"