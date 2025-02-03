using Random

const ndat 20
const range 0.1
const dv 0.001
const g 9.8

function func(y::Float64, vy::Float64, y0::Float64)
    func = y0 + vy*t - 1/2*g*t*t
end

function calc_chi2(t[]::Float64, y[]::Float64, a::Float64, b::Float64)
    calc_chi2 = 0
    for i::int = 0:ndat-1
        i += 1
        diff == y[i] - func(t[i], a, b)
        calc_chi2 += diff * diff / (s[i]*s[i])
    end
end

function main()

