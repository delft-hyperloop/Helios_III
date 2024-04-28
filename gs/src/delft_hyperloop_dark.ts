// You can also use the generator at https://skeleton.dev/docs/generator to create these values for you
import type { CustomThemeConfig } from '@skeletonlabs/tw-plugin';
export const delft_hyperloop_dark: CustomThemeConfig = {
	name: 'delft_hyperloop_dark',
	properties: {
		// =~= Theme Properties =~=
		"--theme-font-family-base": "system-ui",
		"--theme-font-family-heading": "system-ui",
		"--theme-font-color-base": "0 0 0",
		"--theme-font-color-dark": "255 255 255",
		"--theme-rounded-base": "9999px",
		"--theme-rounded-container": "8px",
		"--theme-border-base": "1px",
		// =~= Theme On-X Colors =~=
		"--on-primary": "0 0 0",
		"--on-secondary": "255 255 255",
		"--on-tertiary": "0 0 0",
		"--on-success": "0 0 0",
		"--on-warning": "0 0 0",
		"--on-error": "255 255 255",
		"--on-surface": "255 255 255",
		// =~= Theme Colors  =~=
		// primary | #0FBA81 
		"--color-primary-50": "239 248 244", // #EFF8F4
		"--color-primary-100": "204 227 221", // #cff1e6
		"--color-primary-200": "191 220 213", // #c3eee0
		"--color-primary-300": "153 199 187", // #9fe3cd
		"--color-primary-400": "113 173 159", // #57cfa7
		"--color-primary-500": "77 156 137", // #0FBA81
		"--color-primary-600": "0 114 86", // #0ea774
		"--color-primary-700": "7 80 62", // #0b8c61
		"--color-primary-800": "7 49 39", // #09704d
		"--color-primary-900": "6 25 20", // #075b3f
		// secondary | #4F46E5 
		"--color-secondary-50": "239 248 244", // #e5e3fb
		"--color-secondary-100": "204 227 221", // #dcdafa
		"--color-secondary-200": "191 220 213", // #d3d1f9
		"--color-secondary-300": "153 199 187", // #b9b5f5
		"--color-secondary-400": "77 156 137", // #847eed
		"--color-secondary-500": "77 156 137", // #4F46E5
		"--color-secondary-600": "0 114 86", // #473fce
		"--color-secondary-700": "7 80 62", // #3b35ac
		"--color-secondary-800": "7 49 39", // #2f2a89
		"--color-secondary-900": "6 25 20", // #272270
		// tertiary | #0EA5E9 
		"--color-tertiary-50": "219 242 252", // #dbf2fc
		"--color-tertiary-100": "207 237 251", // #cfedfb
		"--color-tertiary-200": "195 233 250", // #c3e9fa
		"--color-tertiary-300": "159 219 246", // #9fdbf6
		"--color-tertiary-400": "86 192 240", // #56c0f0
		"--color-tertiary-500": "14 165 233", // #0EA5E9
		"--color-tertiary-600": "13 149 210", // #0d95d2
		"--color-tertiary-700": "11 124 175", // #0b7caf
		"--color-tertiary-800": "8 99 140", // #08638c
		"--color-tertiary-900": "7 81 114", // #075172
		// success | #84cc16 
		"--color-success-50": "237 247 220", // #edf7dc
		"--color-success-100": "230 245 208", // #e6f5d0
		"--color-success-200": "224 242 197", // #e0f2c5
		"--color-success-300": "206 235 162", // #ceeba2
		"--color-success-400": "169 219 92", // #a9db5c
		"--color-success-500": "132 204 22", // #84cc16
		"--color-success-600": "119 184 20", // #77b814
		"--color-success-700": "99 153 17", // #639911
		"--color-success-800": "79 122 13", // #4f7a0d
		"--color-success-900": "65 100 11", // #41640b
		// warning | #EAB308 
		"--color-warning-50": "252 244 218", // #fcf4da
		"--color-warning-100": "251 240 206", // #fbf0ce
		"--color-warning-200": "250 236 193", // #faecc1
		"--color-warning-300": "247 225 156", // #f7e19c
		"--color-warning-400": "240 202 82", // #f0ca52
		"--color-warning-500": "234 179 8", // #EAB308
		"--color-warning-600": "211 161 7", // #d3a107
		"--color-warning-700": "176 134 6", // #b08606
		"--color-warning-800": "140 107 5", // #8c6b05
		"--color-warning-900": "115 88 4", // #735804
		// error | #D41976 
		"--color-error-50": "249 221 234", // #f9ddea
		"--color-error-100": "246 209 228", // #f6d1e4
		"--color-error-200": "244 198 221", // #f4c6dd
		"--color-error-300": "238 163 200", // #eea3c8
		"--color-error-400": "225 94 159", // #e15e9f
		"--color-error-500": "212 25 118", // #D41976
		"--color-error-600": "191 23 106", // #bf176a
		"--color-error-700": "159 19 89", // #9f1359
		"--color-error-800": "127 15 71", // #7f0f47
		"--color-error-900": "104 12 58", // #680c3a
		// surface | #495a8f 
		"--color-surface-50": "239 240 240", // #e4e6ee
		"--color-surface-100": "226 228 228", // #dbdee9
		"--color-surface-200": "196 202 202", // #d2d6e3
		"--color-surface-300": "167 175 175", // #b6bdd2
		"--color-surface-400": "137 149 149", // #808cb1
		"--color-surface-500": "109 121 121", // #495a8f
		"--color-surface-600": "82 91 91", // #425181
		"--color-surface-700": "44 48 48", // #37446b
		"--color-surface-800": "34 36 36", // #2c3656
		"--color-surface-900": "28 31 31", // #242c46
	}
}