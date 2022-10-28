package com.example.firstandroidapp;

import android.text.method.PasswordTransformationMethod;
import android.view.View;

import androidx.annotation.NonNull;

public class PasswordMaskTransformation extends PasswordTransformationMethod {
    @Override
    public CharSequence getTransformation(CharSequence source, View view) {
        return new PasswordCharSequence(source);
    }

    private class PasswordCharSequence implements CharSequence {
        private CharSequence source;

        public PasswordCharSequence(CharSequence source) {
            this.source = source;
        }

        @Override
        public int length() {
            return source.length();
        }

        @Override
        public char charAt(int i) {
            return '*';
        }

        @NonNull
        @Override
        public CharSequence subSequence(int start, int end) {
            return source.subSequence(start, end);
        }
    }
}
