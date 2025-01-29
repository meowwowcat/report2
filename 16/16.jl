using Printf
using Random

const Max_x = 2.0
const Min_x = -2.0
const Max_y = 1.0
const μ = 0.0
const σ = 0.5
const g = 9.8
const dt = 0.001
const OUTPUT = 100


function func(x::Float64)
    exp(-(x-μ) * (x-μ)/(2 * σ*σ))
end

function gen_error()
    max_trial = 1000
    trial_count = 0
    while trial_count < max_trial
        x_rnd = Min_x + rand() * (Max_x- Min_x)
        y_try = rand() * Max_y
        y_ref = func(x_rnd)
        if y_try <= y_ref
            return x_rnd
        end
        trial_count += 1
    end

end

function main()

        x::Float64 = 10.0
        y::Float64 = 5.0
        vx::Float64 = 4.0
        vy::Float64 = 6.0
        error::Float64 = 0.0
        t::Float64 = 0.0

        open("u1.dat","w") do fp
            cou::Int64 = 0

#            @printf(fp,"%8.3f,%8.3f,%8.3f,%8.3f,   0.000\n",t,x,y,y)

            for t = 0.0 : dt :2.0
#                error = 0
                error = gen_error()
                @printf("%8.3f,%8.3f,%8.3f,%8.3f,%8.3f\n",t,x,y,y+error,error)
#                cou += 1

                if cou == OUTPUT
                    @printf(fp,"%8.3f,%8.3f,%8.3f,%8.3f,%8.3f\n",t,x,y,y+error,error)
                    cou = 0
                end
                cou += 1

                vy -= g * dt
                x +=vx * dt
                y += vy * dt
            end
         end
end

main()
