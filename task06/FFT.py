import numpy as np
from IPython import embed


def calc_error(M1, M2):

    absolute_error = np.abs(M2 - M1)
    relative_error = absolute_error / np.abs(M1)

    mean_sq_abs_error = np.mean(absolute_error**2)
    median_sq_abs_error = np.median(absolute_error**2)

    mean_sq_rel_error = np.mean(relative_error**2)
    median_sq_rel_error = np.median(relative_error**2)


    rms_abs_error = np.sqrt(mean_sq_abs_error)
    rmds_abs_error = np.sqrt(median_sq_abs_error)

    rms_rel_error = np.sqrt(mean_sq_rel_error)
    rmds_rel_error = np.sqrt(median_sq_rel_error)


    print(f"Mean Absolute Error      = {rms_abs_error:.3e}")
    print(f"Median Absolute Error    = {rmds_abs_error:.3e}")
    print(f"Mean Relative Error      = {rms_rel_error:.3e}")
    print(f"Median Relative Error    = {rmds_rel_error:.3e}")



def main():

    print("Generating 1000x1000 Gaussian matrix...")
    np.random.seed(0)
    A = np.random.normal(loc=1.0, scale=1.0, size=(1000, 1000))

    print("\nFFT complex to complex: calculation of matrix C and reconstruction of A_reco1...")
    C = np.fft.fft2(A)
    A_reco1 = np.fft.ifft2(C).real
    calc_error(A, A_reco1)

    print("\nFFT real to complex calculation of matrix R and reconstruction of A_reco2...")
    R = np.fft.rfft2(A)
    A_reco2 = np.fft.irfft2(R, s=A.shape)
    calc_error(A, A_reco2)

    print("\nMachine precision: %e" % np.finfo(float).eps)

    print("\n")
    print(f"C[0,0]: {C[0, 0]:.16f}")
    print(f"R[0,0]: {R[0, 0]:.16f}")
    print(f"Sum of all elements in matrix A: {np.sum(A):.16f}")


    print("\n")
    M, N = 6, 6
    A_red = A[:M, :N]
    print("Matrix A reduced to shape: ", A_red.shape)

    print("Reconstructing C from R...")
    
    R_red = np.fft.rfft2(A_red)
    C_red = np.fft.fft2(A_red)
    C_red_reco = np.zeros((M, N), dtype=complex)

    C_red_reco[:, :N//2 + 1] = R_red
    for m in range(M):
        for n in range(N//2 + 1, N):
            mm = (-m) % M
            nn = (-n) % N
            #print(f"Setting C_red_reco[{m}, {n}] to conj of C_red_reco[{mm}, {nn}]")
            C_red_reco[m, n] = np.conj(C_red_reco[mm, nn])
    

    calc_error(C_red, C_red_reco)


if __name__ == "__main__":
    main()