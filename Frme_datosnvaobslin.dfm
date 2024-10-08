object Frame_datosnvaobslin: TFrame_datosnvaobslin
  Left = 0
  Top = 0
  Width = 573
  Height = 73
  TabOrder = 0
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 573
    Height = 73
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    object Label5: TLabel
      Left = 44
      Top = 28
      Width = 29
      Height = 13
      Caption = 'Orden'
    end
    object Label6: TLabel
      Left = 169
      Top = 30
      Width = 36
      Height = 13
      Caption = 'F.Inicial'
    end
    object Label7: TLabel
      Left = 377
      Top = 30
      Width = 31
      Height = 13
      Caption = 'F.Final'
    end
    object Label8: TLabel
      Left = 9
      Top = 6
      Width = 71
      Height = 13
      Caption = '&Observaciones'
      FocusControl = edt_obser
    end
    object edt_ordobs: TdxCurrencyEdit
      Left = 84
      Top = 25
      Width = 40
      Hint = 
        'El orden establece la posicion  de las observaciones en la impre' +
        'sion'
      TabOrder = 1
      Alignment = taRightJustify
      DecimalPlaces = 0
      DisplayFormat = '0;-0'
      StoredValues = 1
    end
    object edt_obser: TdxEdit
      Left = 84
      Top = 3
      Width = 481
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Lucida Console'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      Anchors = [akLeft, akTop, akRight]
      CharCase = ecUpperCase
      MaxLength = 70
      StoredValues = 2
    end
    object lkcmb_fonini: TDBLookupComboBox
      Left = 212
      Top = 25
      Width = 147
      Height = 21
      Hint = 
        'El Font inicial determina el tipo de letra que rige para esta l�' +
        'nea de observaciones y solo cmabia cuando el font final tiene ot' +
        'ro valor'
      KeyField = 'NUMERO'
      ListField = 'NOMBRE'
      ListSource = dts_fonini
      TabOrder = 2
    end
    object lkcmb_fonfin: TDBLookupComboBox
      Left = 418
      Top = 25
      Width = 147
      Height = 21
      Hint = 
        'El Font final termina un tipo de letra del ultimo font inicial q' +
        'ue rige para esta l�nea de observaciones'
      KeyField = 'NUMERO'
      ListField = 'NOMBRE'
      ListSource = dts_fonfin
      TabOrder = 3
    end
  end
  object qry_fonini: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select 0 as numero, '#39#39' as nombre from fonts where rownum < 2'
      'union'
      'select numero, nombre from fonts where impre = 1 order by numero')
    Left = 116
    Top = 4
  end
  object qry_fonfin: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select 0 as numero, '#39#39' as nombre from fonts where rownum < 2'
      'union'
      'select numero, nombre from fonts where impre = 1 order by numero')
    Left = 160
    Top = 4
  end
  object dts_fonfin: TDataSource
    DataSet = qry_fonfin
    Left = 160
    Top = 40
  end
  object dts_fonini: TDataSource
    DataSet = qry_fonini
    Left = 120
    Top = 40
  end
end
